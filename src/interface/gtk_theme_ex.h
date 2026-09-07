#ifndef FILEZILLA_INTERFACE_GTK_THEME_EX_HEADER
#define FILEZILLA_INTERFACE_GTK_THEME_EX_HEADER

// Applies a small set of structural CSS tweaks (flatter toolbar buttons,
// slimmer scrollbars, rounded tab/panel corners) on top of whatever GTK
// theme (light or dark) the user has selected. No-op on non-GTK3 builds.
void InitModernGtkStyle();

#endif
