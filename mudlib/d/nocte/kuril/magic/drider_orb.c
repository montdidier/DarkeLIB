// Coder: %^GREEN%^nEv!N%^RESET
// Darkemud

#include <std.h>
#include <nevin.h>
inherit OBJECT;

void init() {
	::init();
	add_action("shatter_orb", "shatter");
	add_action("shatter_orb", "smash");
	add_action("shatter_orb", "break");
	add_action("shatter_orb", "crush");
}

void create() {
	set_name("orb");
	set_id( ({"orb", "magical orb" }) );
	set_short("A crystal orb with a small drider inside");
	set("long",
		"About the size of an egg, this small delicate crystal orb "
		"contains a living creature held in some form of magical "
		"stasis.  You can see a drider inside this orb."
	);
	set_weight(30);
	set_value(600000);
}

int shatter_orb(string str) {
	object ob;

	if(!str) { return 0; }
	if(str == "orb") {
		message("info", "With a loud POP!!!, the orb shatters into "
			"millions of tiny fragments!  From the glittering cloud "
			"emerges a drider which immediately walks up to its "
			"new master.", this_player());
		message("info", (string)this_player()->query_cap_name()+
			" shatters a small crystal orb!  A drider emerges from "
			"the debris.", environment(this_player()),
			({ this_player() }) );
		seteuid(getuid());
		ob = new(MON+"drider");
		ob->set_up();
		ob->set_owner((string)this_player()->query_name());
		ob->move(environment(this_player()));
		write_file("/d/nocte/kuril/logs/orb.log", TPQCN+" shattered "
			"a drider orb at "+ctime(time())+".\n");
		this_object()->remove();
		return 1;
	}
	return 0;
}
