/*
 * test-client.c
 *
 *  Created on: 03-11-2008
 *      Author: christian
 */
#include <dbus/dbus-glib.h>
#include <stdio.h>
#include <stdlib.h>

static void lose (const char *fmt, ...) G_GNUC_NORETURN G_GNUC_PRINTF (1, 2);
static void lose_gerror (const char *prefix, GError *error) G_GNUC_NORETURN;

static void
lose (const char *str, ...)
{
  va_list args;

  va_start (args, str);

  vfprintf (stderr, str, args);
  fputc ('\n', stderr);

  va_end (args);

  exit (1);
}

static void
lose_gerror (const char *prefix, GError *error)
{
  lose ("%s: %s", prefix, error->message);
}

static void
print_hash_value (gpointer key, gpointer val, gpointer data)
{
  printf ("%s -> %s\n", (char *) key, (char *) val);
}

int
main (int argc, char **argv)
{
  DBusGConnection *bus;
  DBusGProxy *remote_object_introspectable;
  DBusGProxy *remote_object_xanguli;
  GError *error = NULL;
  char **reply_list;
  char **reply_ptr;
  GValueArray *hello_reply_struct;
  GHashTable *hello_reply_dict;
  char *introspect_data;
  char *path;
  guint i;

  g_type_init ();

  {
    GLogLevelFlags fatal_mask;

    fatal_mask = g_log_set_always_fatal (G_LOG_FATAL_MASK);
    fatal_mask |= G_LOG_LEVEL_WARNING | G_LOG_LEVEL_CRITICAL;
    g_log_set_always_fatal (fatal_mask);
  }

  bus = dbus_g_bus_get (DBUS_BUS_SESSION, &error);
  if (!bus)
    lose_gerror ("Couldn't connect to session bus", error);


  remote_object_introspectable = dbus_g_proxy_new_for_name (bus,
							    "org.xanguli.Service",
							    "/Xanguli",
							    "org.freedesktop.DBus.Introspectable");
  if (!dbus_g_proxy_call (remote_object_introspectable, "Introspect", &error,
  			  G_TYPE_INVALID,
  			  G_TYPE_STRING, &introspect_data, G_TYPE_INVALID))
      lose_gerror ("Failed to complete Introspect", error);
  printf ("%s", introspect_data);
  g_free (introspect_data);
  g_object_unref (G_OBJECT (remote_object_introspectable));

  remote_object_xanguli = dbus_g_proxy_new_for_name (bus,
							    "org.xanguli.Service",
							    "/Xanguli",
							    "org.xanguli.Xanguli");
  if (!dbus_g_proxy_call (remote_object_xanguli, "CreateController", &error,
    			  G_TYPE_INVALID,
    			  G_TYPE_STRING, &path, G_TYPE_INVALID))
      lose_gerror ("Failed to complete CreateController", error);
  printf ("%s", path);
  g_free (path);



  exit(0);
}
