#include "filezilla.h"
#include "gtk_theme_ex.h"

#ifdef __WXGTK3__
#include <gtk/gtk.h>

namespace {
// Structural-only CSS: no colours are set here, so the user's chosen GTK
// theme (light or dark, e.g. Adwaita, Adwaita-dark, Breeze, Yaru) still
// controls all colours. This only flattens shapes that otherwise make the
// app look dated: beveled toolbar buttons, thick scrollbars, square tabs.
constexpr char const modern_css[] =
	"toolbar button, toolbar > button {"
	"  border-radius: 6px;"
	"  border-width: 0;"
	"  box-shadow: none;"
	"  background-image: none;"
	"  padding: 3px 4px;"
	"}"
	"toolbar separator {"
	"  min-width: 1px;"
	"  margin: 4px 4px;"
	"}"
	"scrollbar slider {"
	"  min-width: 8px;"
	"  min-height: 8px;"
	"  border-radius: 6px;"
	"}"
	"scrollbar trough {"
	"  background-color: transparent;"
	"  border-style: none;"
	"}"
	"notebook > header {"
	"  border-style: none;"
	"  box-shadow: none;"
	"}"
	"notebook > header tabs tab {"
	"  border-radius: 6px 6px 0 0;"
	"  box-shadow: none;"
	"  padding: 4px 12px;"
	"}"
	"entry {"
	"  border-radius: 6px;"
	"}"
	"button {"
	"  border-radius: 6px;"
	"}";
}

void InitModernGtkStyle()
{
	GtkCssProvider* provider = gtk_css_provider_new();

#if GTK_CHECK_VERSION(3, 16, 0)
	gtk_css_provider_load_from_data(provider, modern_css, -1, nullptr);
#else
	GError* error = nullptr;
	gtk_css_provider_load_from_data(provider, modern_css, -1, &error);
	if (error) {
		g_error_free(error);
	}
#endif

	GdkScreen* screen = gdk_screen_get_default();
	if (screen) {
		gtk_style_context_add_provider_for_screen(
			screen,
			GTK_STYLE_PROVIDER(provider),
			GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
	}

	g_object_unref(provider);
}

#else

void InitModernGtkStyle()
{
}

#endif
