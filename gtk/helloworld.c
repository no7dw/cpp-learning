#include <gtk/gtk.h>
/* 这是一个回调函数。data 参数在本示例中被忽略。
* 后面有更多的回调函数示例。*/
void hello( GtkWidget *widget,
gpointer data )
{
g_print ("Hello World\n");
}
gint delete_event( GtkWidget *widget,
GdkEvent *event,
gpointer data )
{
/* 如果你的 "delete_event" 信号处理函数返回 FALSE，GTK 会发出 "destroy" 信号。
* 返回 TRUE，你不希望关闭窗口。
* 当你想弹出“你确定要退出吗?”对话框时它很有用。*/
g_print ("delete event occurred\n");
/* 改 TRUE 为 FALSE 程序会关闭。*/
return TRUE;
}
/* 另一个回调函数 */
void destroy( GtkWidget *widget,
gpointer data )
{
gtk_main_quit ();
}
int main( int argc,
char *argv[] )
{
/* GtkWidget 是构件的存储类型 */
GtkWidget *window;
GtkWidget *button;
/* 这个函数在所有的 GTK 程序都要调用。参数由命令行中解析出来并且送到该程序中*/
gtk_init (&argc, &argv);
/* 创建一个新窗口 */
window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
/* 当窗口收到 "delete_event" 信号 (这个信号由窗口管理器发出，通常是“关闭”
* 选项或是标题栏上的关闭按钮发出的)，我们让它调用在前面定义的 delete_event() 函数。
* 传给回调函数的 data 参数值是 NULL，它会被回调函数忽略。*/
g_signal_connect (G_OBJECT (window), "delete_event",
G_CALLBACK (delete_event), NULL);
/* 在这里我们连接 "destroy" 事件到一个信号处理函数。
* 对这个窗口调用 gtk_widget_destroy() 函数或在 "delete_event" 回调函数中返回 FALSE 值
* 都会触发这个事件。*/
g_signal_connect (G_OBJECT (window), "destroy");
}
