#include <std.h>
#include <nevin.h>

inherit MONSTER;

create() {
	::create();
	set_name("skeleton");
	set("id", ({ "skeleton", "_skeleton1" }) );
        set_level(2);
	set("short", "The bony skeleon heads toward you.");
	set("long", "Its vacant gaze tell you that there's no talking your way out of this.");
	set("race", "skeleton");
	set_body_type("human");
	set_overall_ac(4);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_skill("melee", 10);
	set_skill("attack", 10);
	set_skill("blunt", 10);
	set("aggressive", 0);
	new(WEAP+"leg_bone.c")->
		move(this_object());
	force_me("wield bone in right hand");
}
