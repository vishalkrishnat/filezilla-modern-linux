# Modifications made in this fork

Per GPL-2.0-or-later section 2(a), this file documents the changes made to
the upstream FileZilla3 source (SVN trunk r11557).

1. **`src/interface/customheightlistctrl.cpp`** — the focused-row dotted
   outline was drawn with a hardcoded black (`wxColour(0, 0, 0)`) pen, which
   is nearly invisible against dark selection/background colors. Changed to
   use `wxSYS_COLOUR_WINDOWTEXT` so the outline stays visible in both light
   and dark themes.

2. **`src/interface/gtk_theme_ex.{h,cpp}` (new files)** — on GTK3 Linux
   builds only, installs an application-priority `GtkCssProvider` with
   purely structural CSS (border radius, padding, scrollbar sizing) for
   toolbar buttons, scrollbars, notebook tabs, and entries/buttons. No
   colors are set, so the active GTK theme (light or dark) still controls
   all coloring. Wired up from `CFileZillaApp::OnInit()` in
   `src/interface/FileZilla.cpp`, before any windows are created. No-op on
   non-GTK3 platforms.

3. **`src/interface/aboutdialog.cpp`** — added a line to the About dialog
   disclosing that this is an unofficial fork, not affiliated with the
   FileZilla Project.

4. **`data/filezilla.desktop`** — changed the desktop entry `Name=` from
   `FileZilla` to `FileZilla Modern` to avoid confusion with the official
   build in a user's application launcher.

5. **`src/interface/FileZilla.cpp`** — changed `SetAppDisplayName()` from
   `FileZilla` to `FileZilla Modern` for the same reason.

6. Renamed the original `README` to `UPSTREAM-README.txt` and added a new
   `README.md` and this file describing the fork.

No other functional, protocol, networking, or security-relevant code was
changed. All engine/transfer code is untouched upstream code.
