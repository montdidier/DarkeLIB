//      /bin/adm/_rid.c
//      from the Nightmare mudlib
//      the administrators command to get rid of players
//      created by Descartes of Borg 01 March 1993
                     
#include <std.h>
#include <daemons.h>
#include <security.h>
#include <bank.h>
#include <dirs.h>

inherit DAEMON;

string admins;

int cmd_rid(string str) {
    object ob;
    string em;
    string *inv, file;
    int i;

    if(!archp(previous_object())) return 0;
/*
    if(!member_group(geteuid(previous_object()), "law")) return 0;
*/
    if(!str) {
        notify_fail("Syntax: <rid [player]>\n");
        return 0;
    }
    str = lower_case(str);                                         
    if(member_group(str, "superuser")) {
        notify_fail("Shyeah...NOT.\n");
        return 0;
    }
    ob = find_player(str);
    if(!ob && !user_exists(str)) {
        notify_fail("No such player: "+capitalize(str)+".\n");
        return 0;
    }
    if(ob) ob->remove();
    if(ob) {
        seteuid(UID_DESTRUCT);
        destruct(ob);
        seteuid(getuid());
    }
    seteuid(UID_USERSAVE);
    if(sscanf(read_file(DIR_USERS+"/"+str[0..0]+"/"+str+".o"),"%*semail \"%s\"%*s", em) == 3)
       EMAIL_D->unregister_email(em);
    rename(DIR_USERS+"/"+str[0..0]+"/"+str+".o", DIR_USERS+"/rid/"+str+".o");
    if(file_size(ACCOUNTS_DIR+str+".o") > -1) rm(ACCOUNTS_DIR+str+".o");
    write(capitalize(str)+" is removed from "+mud_name()+".\n");
    seteuid(UID_LOG);
    log_file("rid", (string)this_player()->query_name()+" rid "+str+": "+ctime(time())+"\n");
    inv = get_dir("/adm/save/objects/saveall/"+explode(str, "")[0]+"/"+str+"/*");
    for(i=0;i<sizeof(inv);i++){
        file = "/adm/save/objects/saveall/"+explode(str, "")[0]+"/"+str+"/"+inv[i];
        rm(file);
        rmdir("/adm/save/objects/saveall/"+explode(str, "")[0]+"/"+str);
    }
    seteuid(getuid());
    return 1;
}

void help() {
  write( @EndText
Syntax: rid <name>
Effect: Deletes, nukes, wipes out and annhilates unwanted player <name>
See also: demote, promote, sponsor
EndText
  );
}
