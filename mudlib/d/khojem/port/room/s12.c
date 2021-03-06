//      Wizard:  Khojem
//      s12.c

#include <std.h>
inherit ROOM;

int no_exit() { return 1;}

int check_mobs();
int my_mob_filter(object mob);

int check_mobs() {
  object *all;

  all = filter_array(livings(), "my_mob_filter", this_object());
  if(!all) return 0;
  return sizeof(all);
}

int my_mob_filter(object mob) {
  if(base_name(mob) == "/wizards/khojem/port/mon/peon")  
    return 1;                                        
  return 0;
}

void reset(){
  if(!present("peon")) {
    if(check_mobs()<5)
      new("/wizards/khojem/port/mon/peon")->move(this_object());
  }
}

void init() {
    ::init();
    add_action("read", "read");
    if(this_player()->query_kho_mon()) {
      add_action("no_exit","west");
    }
}

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light",2);
    set_property("indoors", 0);
    set("short", "Wharf Street");
    set("long","Wharf Street extends north and south.  "+
      "The harbor is just to the east.  "+
      "A tall tower is far off to the north.  "+
      "The wooden boards beneath your feet creak with every footstep.  "+
      "Some sort of shop is to the west.  A sign is above the open doorway."
    );
    add_exit("/wizards/khojem/port/shop/shipwright","west");
    add_exit("/wizards/khojem/port/room/s11","north");
    add_exit("/wizards/khojem/port/room/s13","south");
    set_items(([
     ({ "shop","doorway" }) :
        "A broad doorway serves as an entrance to a place of business.  "+
        "A sign hangs above the doorway.",
     ({ "tower" }) :
        "It is a straight, cylindrical tower.",
     ({ "sign" }) :
        "It is an old, weather-beaten sign.  Try reading it.",
     ({ "boards","wooden boards" }) :
        "The wooden boards of the dock are supported above the water my timbers.  "+
        "The boards are bleached from exposure to sun and salt air.",
     ({ "street","dirt street","Wharf Street","wharf street","dock" }) :
        "Wharf Street is nothing more than a wooden deck supported above the water."
    ]));
    set_smell("default", "The smell of the sea fills the air.");
    set_listen("default", "Waves in the harbor lap against the dock's pilings.");
}

int read(string str) {
    write("\n    Othar, the Shipwright\n");
	return 1;
}

