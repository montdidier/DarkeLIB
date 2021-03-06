//      From Maxwell's Underground mudlib
//        68th Room of Dwarf Mining Zone

#include <std.h>
#include <under.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "You are standing in an mining tunnel.");
    set("long", 
"You are standing in a cramped tunnel. The rough walls are jagged and cut "
"at sharp angles where the miners dug out gems.\nThere is a large "
"opening in the ceiling of the room here.\nThere is a large ladder in "
"the opening."); 
    set_exits( ({ UNDER+"dm68a", UNDER+"dm68c" }),
      ({"ladder","south" })
    );
    set_items( ([
    "ladder" : "The wooden ladder is made from Dwarven Oak.",
       ]) );
       
    set_smell("default", "You can smell the dust in the air.");
    set_listen("default", "You hear the sounds of mining in the distance.");
}
