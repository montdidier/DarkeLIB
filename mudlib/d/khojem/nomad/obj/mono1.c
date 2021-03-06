// Wizard:  Khojem
// monolith 1
// mono1.c

#include <move.h>

inherit "/std/Object";

void init() {
     ::init();
  add_action("do_mono","read");
}

int move(object dest) {
  if(living(dest)) return MOVE_NOT_ALLOWED;
  else return ::move(dest);
}

void create() {
  ::create();
  set_name("monolith1");
  set_id(({ "darke monolith","monolith" }) );
  set_short("a darke monolith");
  set_long("The darke, black monolith stands upright out of the sand before "+
    "you.  The rock's surface is near translucent.  It is finely "+
    "crafted from a single, huge rock.  Cryptic letters are raised upon its "+
    "surface.  Perhaps you can read it."
  );
}

int clean_up() { return 0; }

int do_mono(string str) {
  if(str != "monolith" && str != "darke monolith")
    return 0;
  else
    write("Wastelands of Bir'Barrutt\n\n"+
      "Brought to you by Wizard Khojem\n"+
      "Some parts of this area may not be open yet.\n"+
      "Finger Khojem to check on its availability.\n"
    );
    return 1;
}
