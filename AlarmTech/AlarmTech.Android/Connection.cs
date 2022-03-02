using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using MySqlConnector;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AlarmTech.Droid
{
    public class Connection
    {
        public MySqlConnection con;
        public bool TryConnection(Context context)
        {
            MySqlConnectionStringBuilder Builder = new MySqlConnectionStringBuilder();
            Builder.Port = 3306;
            Builder.Server = "sql3.freemysqlhosting.net";
            Builder.Database = "sql3476285";
            Builder.UserID = "sql3476285";
            Builder.Password = "MZ2gvs5Ef4";
            try
            {
                con = new MySqlConnection(Builder.ToString());
                con.Open();
                return true;


            }
            catch (Exception e)
            {

                Toast.MakeText(context, e.ToString(), ToastLength.Long).Show();
                return false;
            }

        }
    }
}
// bd: alarm_tech_db
// usuario: kn_mct
// contraseña: 7(DR@IRa7UMAMSlH
// correo: yulvillegasglz@gmail.com
// host: db4free.net