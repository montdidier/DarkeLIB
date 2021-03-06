//  Wizard:   Khojem
//  File:     citizen2.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();

create() {
  object money;
  int    flip_coin,zlevel,roll;  
  ::create();
    set_name("citizen");
    set_id( ({ "citizen", "mob" }) );
    roll=random(10);
    switch(roll){
      case 0:zlevel=6;break;
      case 1:zlevel=6;break;
      case 2:zlevel=6;break;
      case 3:zlevel=6;break;
      case 4:zlevel=6;break;
      case 5:zlevel=6;break;
      case 6:zlevel=7;break;
      case 7:zlevel=7;break;
      case 8:zlevel=7;break;
      case 9:zlevel=8;break;
    }
    set_level(zlevel);
    set_short("citizen");
    set_long("The citizen is tending to the daily chores." 
      );
    set("race", "pech");
    flip_coin=random(2);
    if(flip_coin)
      set_gender("male");
    else set_gender("female");
    set_body_type("human");
    set_property("melee damage", ([ "crushing" : 12]));
    set_overall_ac(8);
    set_moving(1);
    set_speed(200);
    set_wimpy(10);
    money=new("std/obj/coins");
    money->set_money("silver",(random(60)+(10*zlevel)));
    money->move(this_object());
}

int query_kho_mon() { return 1;}

