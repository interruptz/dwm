/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-fixed-medium-r-*-*-16-*-*-*-*-*-*-*,\
                                       -*-gothic-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#007733";
static const char selbgcolor[]      = "#007733";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const double defaultopacity  = 1.0;

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
	{ "Clock",    NULL,       NULL,       0,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.70; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* Debug option */
#define _DEBUG_INSTANCE

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "terminator", NULL };
static const char *fmcmd[]  = { "thunar", NULL };
static const char *browsercmd[]  = { "chromium", NULL };

#include "exresize.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
  { MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("transset-df -a --dec .1") },
  { MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("transset-df -a --inc .1") },
  { MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("transset-df -a 1.0") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	{ MODKEY,                       XK_KP_7,   explace,                {.ui = EX_NW }},
	{ MODKEY,                       XK_KP_8,   explace,                {.ui = EX_N  }},
	{ MODKEY,                       XK_KP_9,   explace,                {.ui = EX_NE }},
	{ MODKEY,                       XK_KP_4,   explace,                {.ui = EX_W  }},
	{ MODKEY,                       XK_KP_5,   explace,                {.ui = EX_C  }},
	{ MODKEY,                       XK_KP_6,   explace,                {.ui = EX_E  }},
	{ MODKEY,                       XK_KP_1,   explace,                {.ui = EX_SW }},
	{ MODKEY,                       XK_KP_2,   explace,                {.ui = EX_S  }},
	{ MODKEY,                       XK_KP_3,   explace,                {.ui = EX_SE }},

	{ MODKEY|ShiftMask,             XK_KP_8,   exresize,               {.v = (int []){   0,  25 }}},
	{ MODKEY|ShiftMask,             XK_KP_2,   exresize,               {.v = (int []){   0, -25 }}},
	{ MODKEY|ShiftMask,             XK_KP_6,   exresize,               {.v = (int []){  25,   0 }}},
	{ MODKEY|ShiftMask,             XK_KP_4,   exresize,               {.v = (int []){ -25,   0 }}},
	{ MODKEY|ShiftMask,             XK_KP_5,   exresize,               {.v = (int []){  25,  25 }}},
	{ MODKEY|ShiftMask|ControlMask, XK_KP_5,   exresize,               {.v = (int []){ -25, -25 }}},

	{ MODKEY|ControlMask,           XK_KP_6,   togglehorizontalexpand, {.i = +1} },
	{ MODKEY|ControlMask,           XK_KP_3,   togglehorizontalexpand, {.i =  0} },
	{ MODKEY|ControlMask,           XK_KP_4,   togglehorizontalexpand, {.i = -1} },
	{ MODKEY|ControlMask,           XK_KP_8,   toggleverticalexpand,   {.i = +1} },
	{ MODKEY|ControlMask,           XK_KP_1,   toggleverticalexpand,   {.i =  0} },
	{ MODKEY|ControlMask,           XK_KP_2,   toggleverticalexpand,   {.i = -1} },
	{ MODKEY|ControlMask,           XK_KP_9,   togglemaximize,         {.i = -1} },
	{ MODKEY|ControlMask,           XK_KP_7,   togglemaximize,         {.i = +1} },
	{ MODKEY|ControlMask,           XK_KP_5,   togglemaximize,         {.i =  0} },
	{ MODKEY|ControlMask,           XK_Return, spawn,                  {.v = browsercmd } },
	{ ControlMask|ShiftMask,        XK_Return, spawn,                  {.v = fmcmd } },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


