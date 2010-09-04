// this file is part of liqbase by Gary Birkett
		
#include <liqbase/liqbase.h>
#include <liqbase/liqcell.h>
#include <liqbase/liqcell_prop.h>
#include <liqbase/liqcell_easyrun.h>
#include <liqbase/liqcell_easyhandler.h>
		
		
//#####################################################################
//#####################################################################
//##################################################################### liqcalc_run :: by gary birkett
//#####################################################################
//#####################################################################
		
		
		
int liqcalc_add_op(liqcell *self,const char operation)
{
	// check stack for pending operation
	//  perform opeation on lcd,op,stack2
	// push the current lcd caption to the stack
	// push the new operation to the stack
	// reset lcd ready for next operation
	
	liqcell *calclcd = liqcell_child_lookup(self, "calclcd");
	liqcell *calcstack = liqcell_child_lookup(self, "calcstack");
	char *cap = liqcell_getcaption(calclcd);

	return 0;
}		
		
		
int liqcalc_adddot(liqcell *self)
{
	// append a . to the current caption
	// ensure its valid numerically first
	// if its "0", just use the new cap
	// if its blank, use "0."
	liqcell *calclcd = liqcell_child_lookup(self, "calclcd");
	char *cap = liqcell_getcaption(calclcd);
	if(!cap)cap="";
	if(*cap && !isdigit(*cap))cap="";
	if(strcmp(cap,"0")==0)cap="";
	if(strlen(cap)<9 && strstr(cap,".")==NULL)
	{
		if(!*cap)cap="0";
		char newcap[32];
		snprintf(newcap,sizeof(newcap),"%s%c",cap,'.');
		liqcell_setcaption(calclcd,newcap);
	}
	return 0;
}		
		
		
int liqcalc_adddigit(liqcell *self,const char digit)
{
	// append a digit to the current caption
	// ensure its valid numerically first
	// if its "0", just use the new cap
	// 8 DIGITS allowed, though length maybe 9 including .
	liqcell *calclcd = liqcell_child_lookup(self, "calclcd");
	char *cap = liqcell_getcaption(calclcd);
	if(!cap)cap="";
	if(*cap && !isdigit(*cap))cap="";
	if(strcmp(cap,"0")==0)cap="";
	int max=9;
	if(strstr(cap,".")==NULL)max--;
	
	if( (strlen(cap)<max) )
	{
		char newcap[32];
		snprintf(newcap,sizeof(newcap),"%s%c",cap,digit);
		liqcell_setcaption(calclcd,newcap);
	}
	return 0;
}
int liqcalc_clear(liqcell *self)
{
	liqcell *calclcd = liqcell_child_lookup(self, "calclcd");
	liqcell_setcaption(calclcd,"0");
	return 0;
}

int liqcalc_clearall(liqcell *self)
{
	liqcell *calclcd = liqcell_child_lookup(self, "calclcd");
	liqcell_setcaption(calclcd,"0");
	// clear the calc cache
	return 0;
}		
		
		
		
		
//#####################################################################
//#####################################################################
//#####################################################################
//#####################################################################
				
				
		
		
		
		
/**	
 * liqcalc_run widget filter, the system is asking you to filter to the specified .
 */	
static int liqcalc_run_filter(liqcell *self,liqcellfiltereventargs *args, liqcell *context)
{
	// system is indicating the user has typed into the search box
	// you are expected to filter your content based upon this searchterm.
	// show or hide details and rearrange contents to apply this filter.
	char *searchterm = NULL;
	args->resultoutof=0;  // total number of searchable contents
	args->resultshown=0;  // count of options remaining after filtering.
	searchterm = args->searchterm;
	if(searchterm && *searchterm)
	{
		 // check the name property
		 args->resultoutof++;
		 if( stristr(self->name,searchterm) != NULL )
		 {
			  args->resultshown++;
		 }
		 // check the classname property
		 args->resultoutof++;
		 if( stristr(self->classname,searchterm) != NULL )
		 {
			  args->resultshown++;
		 }
		 // check any other properties or children and increment counters
		 // filter out list items recursively
	}
	return 0;
}
/**	
 * liqcalc_run widget refresh, all params set, present yourself to the user.
 */	
static int liqcalc_run_refresh(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * liqcalc_run dialog_open - the user zoomed into the dialog
 */	
static int liqcalc_run_dialog_open(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * liqcalc_run dialog_close - the dialog was closed
 */	
static int liqcalc_run_dialog_close(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	 return 0;
}
/**	
 * liqcalc_run widget shown - occurs once per lifetime
 */	
static int liqcalc_run_shown(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	return 0;
}
/**	
 * liqcalc_run mouse - occurs all the time as you stroke the screen
 */	
static int liqcalc_run_mouse(liqcell *self, liqcellmouseeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * liqcalc_run click - occurs when a short mouse stroke occured
 */	
static int liqcalc_run_click(liqcell *self, liqcellclickeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * liqcalc_run keypress - the user pressed a key
 */	
static int liqcalc_run_keypress(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * liqcalc_run keyrelease - the user released a key
 */	
static int liqcalc_run_keyrelease(liqcell *self, liqcellkeyeventargs *args,liqcell *context)
{
	return 0;
}
/**	
 * liqcalc_run paint - being rendered.  use the vgraph held in args to do custom drawing at scale
 */	
static int liqcalc_run_paint(liqcell *self, liqcellpainteventargs *args,liqcell *liqcalc_run)
{
	// big heavy event, use sparingly
	liqcell *solarcell = liqcell_child_lookup(liqcalc_run, "solarcell");
	liqcell *calclcd = liqcell_child_lookup(liqcalc_run, "calclcd");
	if( liqcell_easyrun_getactivecontrol() == solarcell && liqcell_easyrun_fingerpressed)
	{
		
		// fade the text..
		int solarbrightness = liqcell_propgeti(calclcd,"solarbrightness",255);
		liqapp_log("solar -- %d",solarbrightness);
		if(solarbrightness>0)
		{
			
			solarbrightness-=4;
			if(solarbrightness<0)solarbrightness=0;
			if(solarbrightness>255)solarbrightness=255;
			liqcell_propsets_printf(calclcd,"backcolor","rgb(%d,%d,%d)",solarbrightness,solarbrightness,solarbrightness);
			liqcell_propseti(  calclcd, "solarbrightness", solarbrightness );
			liqcell_setdirty(calclcd,1);
		}
	}
	else
	{
		
		int solarbrightness = liqcell_propgeti(calclcd,"solarbrightness",255);
		liqapp_log("solar ++ %d",solarbrightness);
		if(solarbrightness<255)
		{
			
			solarbrightness+=16;
			if(solarbrightness<0)solarbrightness=0;
			if(solarbrightness>255)solarbrightness=255;
			liqcell_propsets_printf(calclcd,"backcolor","rgb(%d,%d,%d)",solarbrightness,solarbrightness,solarbrightness);
			liqcell_propseti(  calclcd, "solarbrightness", solarbrightness );
			liqcell_setdirty(calclcd,1);
		}
		// bring the text back up ;)
	}
	return 0;
}
/**	
 * liqcalc_run dynamic resizing
 */	
static int liqcalc_run_resize(liqcell *self,liqcelleventargs *args, liqcell *context)
{
	float sx=((float)self->w)/((float)self->innerw);
	float sy=((float)self->h)/((float)self->innerh);
	
	liqcell *solarcell = liqcell_child_lookup(self, "solarcell");
	liqcell *cmdplusminus = liqcell_child_lookup(self, "cmdplusminus");
	liqcell *label21 = liqcell_child_lookup(self, "label21");
	liqcell *label4 = liqcell_child_lookup(self, "label4");
	liqcell *label26 = liqcell_child_lookup(self, "label26");
	liqcell *cmdsqr = liqcell_child_lookup(self, "cmdsqr");
	liqcell *cmdmrc = liqcell_child_lookup(self, "cmdmrc");
	liqcell *cmdmneg = liqcell_child_lookup(self, "cmdmneg");
	liqcell *cmdmplus = liqcell_child_lookup(self, "cmdmplus");
	liqcell *cmddivide = liqcell_child_lookup(self, "cmddivide");
	liqcell *cmdac = liqcell_child_lookup(self, "cmdac");
	liqcell *cmdc = liqcell_child_lookup(self, "cmdc");
	liqcell *cmdpercent = liqcell_child_lookup(self, "cmdpercent");
	liqcell *cmdmul = liqcell_child_lookup(self, "cmdmul");
	liqcell *cmdminus = liqcell_child_lookup(self, "cmdminus");
	liqcell *cmdplus = liqcell_child_lookup(self, "cmdplus");
	liqcell *cmd7 = liqcell_child_lookup(self, "cmd7");
	liqcell *cmd8 = liqcell_child_lookup(self, "cmd8");
	liqcell *cmd9 = liqcell_child_lookup(self, "cmd9");
	liqcell *cmd4 = liqcell_child_lookup(self, "cmd4");
	liqcell *cmd5 = liqcell_child_lookup(self, "cmd5");
	liqcell *cmd6 = liqcell_child_lookup(self, "cmd6");
	liqcell *cmd1 = liqcell_child_lookup(self, "cmd1");
	liqcell *cmd2 = liqcell_child_lookup(self, "cmd2");
	liqcell *cmd3 = liqcell_child_lookup(self, "cmd3");
	liqcell *cmd0 = liqcell_child_lookup(self, "cmd0");
	liqcell *cmddot = liqcell_child_lookup(self, "cmddot");
	liqcell *cmdequals = liqcell_child_lookup(self, "cmdequals");
	liqcell *title = liqcell_child_lookup(self, "title");
	liqcell *calclcd = liqcell_child_lookup(self, "calclcd");
	liqcell_setrect_autoscale( solarcell, 208,166, 254,50, sx,sy);
	liqcell_setrect_autoscale( cmdplusminus, 384,232, 78,42, sx,sy);
	liqcell_setrect_autoscale( label21, 50,116, 44,36, sx,sy);
	liqcell_setrect_autoscale( label4, 50,64, 44,36, sx,sy);
	liqcell_setrect_autoscale( label26, 50,88, 44,36, sx,sy);
	liqcell_setrect_autoscale( cmdsqr, 296,232, 78,42, sx,sy);
	liqcell_setrect_autoscale( cmdmrc, 20,232, 78,42, sx,sy);
	liqcell_setrect_autoscale( cmdmneg, 106,232, 78,42, sx,sy);
	liqcell_setrect_autoscale( cmdmplus, 192,232, 78,42, sx,sy);
	liqcell_setrect_autoscale( cmddivide, 370,292, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdac, 20,292, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdc, 140,292, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdpercent, 256,292, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdmul, 370,394, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdminus, 370,496, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdplus, 370,596, 92,190, sx,sy);
	liqcell_setrect_autoscale( cmd7, 20,394, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd8, 140,394, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd9, 256,394, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd4, 20,496, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd5, 140,496, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd6, 256,496, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd1, 20,598, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd2, 140,598, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd3, 256,598, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmd0, 20,700, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmddot, 140,700, 92,86, sx,sy);
	liqcell_setrect_autoscale( cmdequals, 256,700, 92,86, sx,sy);
	liqcell_setrect_autoscale( title, 0,0, 480,56, sx,sy);
	liqcell_setrect_autoscale( calclcd, 94,64, 330,88, sx,sy);
	return 0;
}
/**	
 * liqcalc_run.solarcell mouse
 */	
static int solarcell_mouse(liqcell *self,liqcellmouseeventargs *args, liqcell *liqcalc_run)
{
	//
	liqcell_propseti(liqcalc_run,"solarcell_pressed",1);
	return 0;
}
/**	
 * liqcalc_run.cmdplusminus clicked
 */	
static int cmdplusminus_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdsqr clicked
 */	
static int cmdsqr_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdmrc clicked
 */	
static int cmdmrc_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdmneg clicked
 */	
static int cmdmneg_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdmplus clicked
 */	
static int cmdmplus_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmddivide clicked
 */	
static int cmddivide_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdac clicked
 */	
static int cmdac_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_clearall(liqcalc_run);
	return 0;
}
/**	
 * liqcalc_run.cmdc clicked
 */	
static int cmdc_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_clear(liqcalc_run);
	return 0;
}
/**	
 * liqcalc_run.cmdpercent clicked
 */	
static int cmdpercent_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdmul clicked
 */	
static int cmdmul_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdminus clicked
 */	
static int cmdminus_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmdplus clicked
 */	
static int cmdplus_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run.cmd7 clicked
 */	
static int cmd7_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'7');
	return 0;
}
/**	
 * liqcalc_run.cmd8 clicked
 */	
static int cmd8_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'8');
	return 0;
}
/**	
 * liqcalc_run.cmd9 clicked
 */	
static int cmd9_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'9');
	return 0;
}
/**	
 * liqcalc_run.cmd4 clicked
 */	
static int cmd4_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'4');	
	return 0;
}
/**	
 * liqcalc_run.cmd5 clicked
 */	
static int cmd5_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'5');
	return 0;
}
/**	
 * liqcalc_run.cmd6 clicked
 */	
static int cmd6_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'6');
	return 0;
}
/**	
 * liqcalc_run.cmd1 clicked
 */	
static int cmd1_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'1');
	return 0;
}
/**	
 * liqcalc_run.cmd2 clicked
 */	
static int cmd2_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'2');
	return 0;
}
/**	
 * liqcalc_run.cmd3 clicked
 */	
static int cmd3_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'3');
	return 0;
}
/**	
 * liqcalc_run.cmd0 clicked
 */	
static int cmd0_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddigit(liqcalc_run,'0');
	return 0;
}
/**	
 * liqcalc_run.cmddot clicked
 */	
static int cmddot_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	liqcalc_adddot(liqcalc_run);
	return 0;
}
/**	
 * liqcalc_run.cmdequals clicked
 */	
static int cmdequals_click(liqcell *self,liqcellclickeventargs *args, liqcell *liqcalc_run)
{
	return 0;
}
/**	
 * liqcalc_run_child_test_seek this function shows how to access members
 */	
	  
static void liqcalc_run_child_test_seek(liqcell *liqcalc_run)
{	  
	liqcell *solarcell = liqcell_child_lookup(liqcalc_run, "solarcell");
	liqcell *cmdplusminus = liqcell_child_lookup(liqcalc_run, "cmdplusminus");
	liqcell *label21 = liqcell_child_lookup(liqcalc_run, "label21");
	liqcell *label4 = liqcell_child_lookup(liqcalc_run, "label4");
	liqcell *label26 = liqcell_child_lookup(liqcalc_run, "label26");
	liqcell *cmdsqr = liqcell_child_lookup(liqcalc_run, "cmdsqr");
	liqcell *cmdmrc = liqcell_child_lookup(liqcalc_run, "cmdmrc");
	liqcell *cmdmneg = liqcell_child_lookup(liqcalc_run, "cmdmneg");
	liqcell *cmdmplus = liqcell_child_lookup(liqcalc_run, "cmdmplus");
	liqcell *cmddivide = liqcell_child_lookup(liqcalc_run, "cmddivide");
	liqcell *cmdac = liqcell_child_lookup(liqcalc_run, "cmdac");
	liqcell *cmdc = liqcell_child_lookup(liqcalc_run, "cmdc");
	liqcell *cmdpercent = liqcell_child_lookup(liqcalc_run, "cmdpercent");
	liqcell *cmdmul = liqcell_child_lookup(liqcalc_run, "cmdmul");
	liqcell *cmdminus = liqcell_child_lookup(liqcalc_run, "cmdminus");
	liqcell *cmdplus = liqcell_child_lookup(liqcalc_run, "cmdplus");
	liqcell *cmd7 = liqcell_child_lookup(liqcalc_run, "cmd7");
	liqcell *cmd8 = liqcell_child_lookup(liqcalc_run, "cmd8");
	liqcell *cmd9 = liqcell_child_lookup(liqcalc_run, "cmd9");
	liqcell *cmd4 = liqcell_child_lookup(liqcalc_run, "cmd4");
	liqcell *cmd5 = liqcell_child_lookup(liqcalc_run, "cmd5");
	liqcell *cmd6 = liqcell_child_lookup(liqcalc_run, "cmd6");
	liqcell *cmd1 = liqcell_child_lookup(liqcalc_run, "cmd1");
	liqcell *cmd2 = liqcell_child_lookup(liqcalc_run, "cmd2");
	liqcell *cmd3 = liqcell_child_lookup(liqcalc_run, "cmd3");
	liqcell *cmd0 = liqcell_child_lookup(liqcalc_run, "cmd0");
	liqcell *cmddot = liqcell_child_lookup(liqcalc_run, "cmddot");
	liqcell *cmdequals = liqcell_child_lookup(liqcalc_run, "cmdequals");
	liqcell *title = liqcell_child_lookup(liqcalc_run, "title");
	liqcell *calclcd = liqcell_child_lookup(liqcalc_run, "calclcd");
}	  
/**	
 * create a new liqcalc_run widget
 */	
liqcell *liqcalc_run_create()
{
	liqcell *self = liqcell_quickcreatewidget("liqcalc_run", "form", 480, 800);
	if(!self) {liqapp_log("liqcell error not create 'liqcalc_run'"); return NULL;  } 
	
	// Optimization:  The aim is to REDUCE the number of drawn layers and operations called.
	// Optimization:  use only what you NEED to get an effect
	// Optimization:  Minimal layers and complexity
	// Optimization:  defaults: background, prefer nothing, will be shown through if there is a wallpaper
	// Optimization:  defaults: text, white, very fast rendering
	//############################# title:label
	liqcell *title = liqcell_quickcreatevis("title", "label", 0, 0, 480, 56);
	liqcell_setfont(	title, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(title, "liqcalc" );
	liqcell_propsets(  title, "textcolor", "rgb(255,255,255)" );
	liqcell_propsets(  title, "backcolor", "xrgb(128,128,0)" );
	liqcell_propseti(  title, "textalign", 0 );
	liqcell_propseti(  title, "textaligny", 0 );
	liqcell_child_append(  self, title);
	//############################# calclcd:textbox
	liqcell *calclcd = liqcell_quickcreatevis("calclcd", "label", 94, 64, 330, 88);
	liqcell_setfont(	calclcd, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (60), 0) );
	liqcell_setcaption(calclcd, "12345678" );
	liqcell_propsets(  calclcd, "textcolor", "rgb(0,0,0)" );
	liqcell_propsets(  calclcd, "backcolor", "rgb(255,255,255)" );
	liqcell_propsets(  calclcd, "bordercolor", "rgb(255,255,255)" );
	liqcell_propseti(  calclcd, "textalign", 1 );
	liqcell_propseti(  calclcd, "textaligny", 1 );
	liqcell_propseti(  calclcd, "solarbrightness", 255 );
	liqcell_child_append(  self, calclcd);
	//############################# solarcell:label
	liqcell *solarcell = liqcell_quickcreatevis("solarcell", "label", 208, 166, 254, 50);
	liqcell_setfont(	solarcell, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (32), 0) );
	liqcell_setcaption(solarcell, "SOLAR CELL" );
	liqcell_propsets(  solarcell, "textcolor", "rgb(128,128,128)" );
	liqcell_propsets(  solarcell, "backcolor", "rgb(64,64,64)" );
	liqcell_propseti(  solarcell, "textalign", 2 );
	liqcell_propseti(  solarcell, "textaligny", 2 );
	liqcell_handleradd_withcontext(solarcell, "mouse", (void*)solarcell_mouse, self );
	liqcell_child_append(  self, solarcell);
	//############################# cmdplusminus:label
	liqcell *cmdplusminus = liqcell_quickcreatevis("cmdplusminus", "label", 384, 232, 78, 42);
	liqcell_setfont(	cmdplusminus, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(cmdplusminus, "±" );
	liqcell_propsets(  cmdplusminus, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdplusminus, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmdplusminus, "textalign", 2 );
	liqcell_propseti(  cmdplusminus, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdplusminus, "click", (void*)cmdplusminus_click, self );
	liqcell_child_append(  self, cmdplusminus);
	//############################# label21:label
	liqcell *label21 = liqcell_quickcreatevis("label21", "label", 50, 116, 44, 36);
	liqcell_setfont(	label21, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(label21, "E" );
	liqcell_propsets(  label21, "textcolor", "rgb(0,0,0)" );
	liqcell_propsets(  label21, "backcolor", "rgb(255,255,255)" );
	liqcell_propseti(  label21, "textalign", 2 );
	liqcell_propseti(  label21, "textaligny", 2 );
	liqcell_child_append(  self, label21);
	//############################# label4:label
	liqcell *label4 = liqcell_quickcreatevis("label4", "label", 50, 64, 44, 36);
	liqcell_setfont(	label4, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(label4, "M" );
	liqcell_propsets(  label4, "textcolor", "rgb(0,0,0)" );
	liqcell_propsets(  label4, "backcolor", "rgb(255,255,255)" );
	liqcell_propseti(  label4, "textalign", 2 );
	liqcell_propseti(  label4, "textaligny", 2 );
	liqcell_child_append(  self, label4);
	//############################# label26:label
	liqcell *label26 = liqcell_quickcreatevis("label26", "label", 50, 88, 44, 36);
	liqcell_setfont(	label26, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(label26, "-" );
	liqcell_propsets(  label26, "textcolor", "rgb(0,0,0)" );
	liqcell_propsets(  label26, "backcolor", "rgb(255,255,255)" );
	liqcell_propseti(  label26, "textalign", 2 );
	liqcell_propseti(  label26, "textaligny", 2 );
	liqcell_child_append(  self, label26);
	//############################# cmdsqr:label
	liqcell *cmdsqr = liqcell_quickcreatevis("cmdsqr", "label", 296, 232, 78, 42);
	liqcell_setfont(	cmdsqr, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(cmdsqr, "^2" );
	liqcell_propsets(  cmdsqr, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdsqr, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmdsqr, "textalign", 2 );
	liqcell_propseti(  cmdsqr, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdsqr, "click", (void*)cmdsqr_click, self );
	liqcell_child_append(  self, cmdsqr);
	//############################# cmdmrc:label
	liqcell *cmdmrc = liqcell_quickcreatevis("cmdmrc", "label", 20, 232, 78, 42);
	liqcell_setfont(	cmdmrc, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(cmdmrc, "MRC" );
	liqcell_propsets(  cmdmrc, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdmrc, "backcolor", "xrgb(0,0,128)" );
	liqcell_propseti(  cmdmrc, "textalign", 2 );
	liqcell_propseti(  cmdmrc, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdmrc, "click", (void*)cmdmrc_click, self );
	liqcell_child_append(  self, cmdmrc);
	//############################# cmdmneg:label
	liqcell *cmdmneg = liqcell_quickcreatevis("cmdmneg", "label", 106, 232, 78, 42);
	liqcell_setfont(	cmdmneg, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(cmdmneg, "M-" );
	liqcell_propsets(  cmdmneg, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdmneg, "backcolor", "xrgb(0,0,128)" );
	liqcell_propseti(  cmdmneg, "textalign", 2 );
	liqcell_propseti(  cmdmneg, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdmneg, "click", (void*)cmdmneg_click, self );
	liqcell_child_append(  self, cmdmneg);
	//############################# cmdmplus:label
	liqcell *cmdmplus = liqcell_quickcreatevis("cmdmplus", "label", 192, 232, 78, 42);
	liqcell_setfont(	cmdmplus, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (26), 0) );
	liqcell_setcaption(cmdmplus, "M+" );
	liqcell_propsets(  cmdmplus, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdmplus, "backcolor", "xrgb(0,0,128)" );
	liqcell_propseti(  cmdmplus, "textalign", 2 );
	liqcell_propseti(  cmdmplus, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdmplus, "click", (void*)cmdmplus_click, self );
	liqcell_child_append(  self, cmdmplus);
	//############################# cmddivide:label
	liqcell *cmddivide = liqcell_quickcreatevis("cmddivide", "label", 370, 292, 92, 86);
	liqcell_setfont(	cmddivide, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmddivide, "÷" );
	liqcell_propsets(  cmddivide, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmddivide, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmddivide, "textalign", 2 );
	liqcell_propseti(  cmddivide, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmddivide, "click", (void*)cmddivide_click, self );
	liqcell_child_append(  self, cmddivide);
	//############################# cmdac:label
	liqcell *cmdac = liqcell_quickcreatevis("cmdac", "label", 20, 292, 92, 86);
	liqcell_setfont(	cmdac, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdac, "AC" );
	liqcell_propsets(  cmdac, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdac, "backcolor", "xrgb(128,64,0)" );
	liqcell_propseti(  cmdac, "textalign", 2 );
	liqcell_propseti(  cmdac, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdac, "click", (void*)cmdac_click, self );
	liqcell_child_append(  self, cmdac);
	//############################# cmdc:label
	liqcell *cmdc = liqcell_quickcreatevis("cmdc", "label", 140, 292, 92, 86);
	liqcell_setfont(	cmdc, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdc, "C" );
	liqcell_propsets(  cmdc, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdc, "backcolor", "xrgb(128,64,0)" );
	liqcell_propseti(  cmdc, "textalign", 2 );
	liqcell_propseti(  cmdc, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdc, "click", (void*)cmdc_click, self );
	liqcell_child_append(  self, cmdc);
	//############################# cmdpercent:label
	liqcell *cmdpercent = liqcell_quickcreatevis("cmdpercent", "label", 256, 292, 92, 86);
	liqcell_setfont(	cmdpercent, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdpercent, "%" );
	liqcell_propsets(  cmdpercent, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdpercent, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmdpercent, "textalign", 2 );
	liqcell_propseti(  cmdpercent, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdpercent, "click", (void*)cmdpercent_click, self );
	liqcell_child_append(  self, cmdpercent);
	//############################# cmdmul:label
	liqcell *cmdmul = liqcell_quickcreatevis("cmdmul", "label", 370, 394, 92, 86);
	liqcell_setfont(	cmdmul, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdmul, "X" );
	liqcell_propsets(  cmdmul, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdmul, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmdmul, "textalign", 2 );
	liqcell_propseti(  cmdmul, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdmul, "click", (void*)cmdmul_click, self );
	liqcell_child_append(  self, cmdmul);
	//############################# cmdminus:label
	liqcell *cmdminus = liqcell_quickcreatevis("cmdminus", "label", 370, 496, 92, 86);
	liqcell_setfont(	cmdminus, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdminus, "-" );
	liqcell_propsets(  cmdminus, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdminus, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmdminus, "textalign", 2 );
	liqcell_propseti(  cmdminus, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdminus, "click", (void*)cmdminus_click, self );
	liqcell_child_append(  self, cmdminus);
	//############################# cmdplus:label
	liqcell *cmdplus = liqcell_quickcreatevis("cmdplus", "label", 370, 596, 92, 190);
	liqcell_setfont(	cmdplus, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdplus, "+" );
	liqcell_propsets(  cmdplus, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdplus, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmdplus, "textalign", 2 );
	liqcell_propseti(  cmdplus, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdplus, "click", (void*)cmdplus_click, self );
	liqcell_child_append(  self, cmdplus);
	//############################# cmd7:label
	liqcell *cmd7 = liqcell_quickcreatevis("cmd7", "label", 20, 394, 92, 86);
	liqcell_setfont(	cmd7, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd7, "7" );
	liqcell_propsets(  cmd7, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd7, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd7, "textalign", 2 );
	liqcell_propseti(  cmd7, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd7, "click", (void*)cmd7_click, self );
	liqcell_child_append(  self, cmd7);
	//############################# cmd8:label
	liqcell *cmd8 = liqcell_quickcreatevis("cmd8", "label", 140, 394, 92, 86);
	liqcell_setfont(	cmd8, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd8, "8" );
	liqcell_propsets(  cmd8, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd8, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd8, "textalign", 2 );
	liqcell_propseti(  cmd8, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd8, "click", (void*)cmd8_click, self );
	liqcell_child_append(  self, cmd8);
	//############################# cmd9:label
	liqcell *cmd9 = liqcell_quickcreatevis("cmd9", "label", 256, 394, 92, 86);
	liqcell_setfont(	cmd9, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd9, "9" );
	liqcell_propsets(  cmd9, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd9, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd9, "textalign", 2 );
	liqcell_propseti(  cmd9, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd9, "click", (void*)cmd9_click, self );
	liqcell_child_append(  self, cmd9);
	//############################# cmd4:label
	liqcell *cmd4 = liqcell_quickcreatevis("cmd4", "label", 20, 496, 92, 86);
	liqcell_setfont(	cmd4, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd4, "4" );
	liqcell_propsets(  cmd4, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd4, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd4, "textalign", 2 );
	liqcell_propseti(  cmd4, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd4, "click", (void*)cmd4_click, self );
	liqcell_child_append(  self, cmd4);
	//############################# cmd5:label
	liqcell *cmd5 = liqcell_quickcreatevis("cmd5", "label", 140, 496, 92, 86);
	liqcell_setfont(	cmd5, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd5, "5" );
	liqcell_propsets(  cmd5, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd5, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd5, "textalign", 2 );
	liqcell_propseti(  cmd5, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd5, "click", (void*)cmd5_click, self );
	liqcell_child_append(  self, cmd5);
	//############################# cmd6:label
	liqcell *cmd6 = liqcell_quickcreatevis("cmd6", "label", 256, 496, 92, 86);
	liqcell_setfont(	cmd6, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd6, "6" );
	liqcell_propsets(  cmd6, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd6, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd6, "textalign", 2 );
	liqcell_propseti(  cmd6, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd6, "click", (void*)cmd6_click, self );
	liqcell_child_append(  self, cmd6);
	//############################# cmd1:label
	liqcell *cmd1 = liqcell_quickcreatevis("cmd1", "label", 20, 598, 92, 86);
	liqcell_setfont(	cmd1, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd1, "1" );
	liqcell_propsets(  cmd1, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd1, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd1, "textalign", 2 );
	liqcell_propseti(  cmd1, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd1, "click", (void*)cmd1_click, self );
	liqcell_child_append(  self, cmd1);
	//############################# cmd2:label
	liqcell *cmd2 = liqcell_quickcreatevis("cmd2", "label", 140, 598, 92, 86);
	liqcell_setfont(	cmd2, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd2, "2" );
	liqcell_propsets(  cmd2, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd2, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd2, "textalign", 2 );
	liqcell_propseti(  cmd2, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd2, "click", (void*)cmd2_click, self );
	liqcell_child_append(  self, cmd2);
	//############################# cmd3:label
	liqcell *cmd3 = liqcell_quickcreatevis("cmd3", "label", 256, 598, 92, 86);
	liqcell_setfont(	cmd3, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd3, "3" );
	liqcell_propsets(  cmd3, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd3, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd3, "textalign", 2 );
	liqcell_propseti(  cmd3, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd3, "click", (void*)cmd3_click, self );
	liqcell_child_append(  self, cmd3);
	//############################# cmd0:label
	liqcell *cmd0 = liqcell_quickcreatevis("cmd0", "label", 20, 700, 92, 86);
	liqcell_setfont(	cmd0, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmd0, "0" );
	liqcell_propsets(  cmd0, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmd0, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmd0, "textalign", 2 );
	liqcell_propseti(  cmd0, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmd0, "click", (void*)cmd0_click, self );
	liqcell_child_append(  self, cmd0);
	//############################# cmddot:label
	liqcell *cmddot = liqcell_quickcreatevis("cmddot", "label", 140, 700, 92, 86);
	liqcell_setfont(	cmddot, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmddot, "." );
	liqcell_propsets(  cmddot, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmddot, "backcolor", "xrgb(64,64,64)" );
	liqcell_propseti(  cmddot, "textalign", 2 );
	liqcell_propseti(  cmddot, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmddot, "click", (void*)cmddot_click, self );
	liqcell_child_append(  self, cmddot);
	//############################# cmdequals:label
	liqcell *cmdequals = liqcell_quickcreatevis("cmdequals", "label", 256, 700, 92, 86);
	liqcell_setfont(	cmdequals, liqfont_cache_getttf("/usr/share/fonts/nokia/nosnb.ttf", (33), 0) );
	liqcell_setcaption(cmdequals, "=" );
	liqcell_propsets(  cmdequals, "textcolor", "rgb(255,255,0)" );
	liqcell_propsets(  cmdequals, "backcolor", "xrgb(0,128,0)" );
	liqcell_propseti(  cmdequals, "textalign", 2 );
	liqcell_propseti(  cmdequals, "textaligny", 2 );
	liqcell_handleradd_withcontext(cmdequals, "click", (void*)cmdequals_click, self );
	liqcell_child_append(  self, cmdequals);

	//liqcell_propsets(  self, "backcolor", "rgb(0,0,0)" );
	//liqcell_setimage(  self ,  liqimage_cache_getfile( "/usr/share/liqbase/liqcalc/media/liqcalc_run_back.png",0,0,0) );
	liqcell_handleradd_withcontext(self, "filter",		 (void*)liqcalc_run_filter ,self);
	liqcell_handleradd_withcontext(self, "refresh",		(void*)liqcalc_run_refresh ,self);
	liqcell_handleradd_withcontext(self, "shown",		  (void*)liqcalc_run_shown ,self);
	liqcell_handleradd_withcontext(self, "resize",	  (void*)liqcalc_run_resize ,self);
	//liqcell_handleradd_withcontext(self, "keypress",	(void*)liqcalc_run_keypress,self );
	//liqcell_handleradd_withcontext(self, "keyrelease", (void*)liqcalc_run_keyrelease ,self);
	//liqcell_handleradd_withcontext(self, "mouse",		(void*)liqcalc_run_mouse,self );
	//liqcell_handleradd_withcontext(self, "click",		(void*)liqcalc_run_click ,self);
	liqcell_handleradd_withcontext(self, "paint",		(void*)liqcalc_run_paint ,self); // use only if required, heavyweight
	liqcell_handleradd_withcontext(self, "dialog_open",  (void*)liqcalc_run_dialog_open ,self);
	liqcell_handleradd_withcontext(self, "dialog_close", (void*)liqcalc_run_dialog_close ,self);
	
	
	liqcell_child_append( self, liqcell_quickcreatenameclass("calcstack","stack") );
	
	liqcalc_clearall(self);
	return self;
}

