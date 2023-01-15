#include <stdio.h>
#include <adwaita.h>

const char* GET_FILE_LIST = "adb -s emulator-5554 shell run-as kr.ac.hallym.watchlogger ls files";

static char** getFiles() {
    return
}

static void
set_margin(GObject *const object, const gint margin) {
    g_object_set(object,
                 "margin-start", margin,
                 "margin-top", margin,
                 "margin-end", margin,
                 "margin-bottom", margin,
                 NULL);
}

static void
activate_cb(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "심박수 로그 데이터 추출기");
    gtk_window_set_default_size(GTK_WINDOW (window), 800, 480);
    gtk_window_present(GTK_WINDOW (window));

    GtkHeaderBar *headerBar = (GtkHeaderBar *) gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW (window), (GtkWidget *) headerBar);

    GtkPaned *paned = (GtkPaned *) gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_window_set_child(GTK_WINDOW (window), (GtkWidget *) paned);

    GtkLabel *label2 = (GtkLabel *) gtk_label_new("기기에 연결되어 있지 않습니다.");


    GtkBox *leftBox = (GtkBox *) gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    set_margin((GObject *) leftBox, 10);

    GtkLabel *ipHint = (GtkLabel *) gtk_label_new("접속 하고자 하는 IP:");
    gtk_label_set_xalign(ipHint, 0.0f);
    gtk_box_append(leftBox, (GtkWidget *) ipHint);

    GtkBox *ipBox = (GtkBox *) gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    GtkEntry *ipField = (GtkEntry *) gtk_entry_new();
    gtk_widget_set_hexpand(((GtkWidget *) ipField), true);
    gtk_box_append(ipBox, (GtkWidget *) ipField);
    GtkButton *btn = (GtkButton *) gtk_button_new();
    gtk_button_set_label(btn, "연결");
    gtk_box_append(ipBox, (GtkWidget *) btn);
    gtk_box_append(leftBox, (GtkWidget *) ipBox);

    gtk_box_append(leftBox, gtk_separator_new(GTK_ORIENTATION_HORIZONTAL));

    GtkLabel *deviceStatusTxt = (GtkLabel *) gtk_label_new("");
    gtk_label_set_markup(deviceStatusTxt, "<b>기기명 : </b>\n<b>연결 상태 : </b>연결 안됨");
    gtk_label_set_xalign(deviceStatusTxt, 0.0f);
    gtk_box_append(leftBox, (GtkWidget *) deviceStatusTxt);

    gtk_paned_set_start_child(paned, (GtkWidget *) leftBox);
    gtk_paned_set_end_child(paned, (GtkWidget *) label2);

    gtk_paned_set_position(paned, 240);
}

int
main(int argc,
     char *argv[]) {
    g_autoptr (AdwApplication) app = NULL;

    app = adw_application_new("org.example.Hello", G_APPLICATION_FLAGS_NONE);

    g_signal_connect (app, "activate", G_CALLBACK(activate_cb), NULL);

    return g_application_run(G_APPLICATION (app), argc, argv);
}