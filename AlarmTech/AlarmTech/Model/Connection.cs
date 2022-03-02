using System;
using System.Collections.Generic;
using System.Text;
using MySqlConnector;
namespace AlarmTech.Model
{
    public class Connection
    {
        public int Id_usuario { get; set; }
        public String Nombre { get; set; }
        public String Apellidos { get; set; }
        public String Correo_electronico { get; set; }
        public String contrasena { get; set; }
        public String fech_c { get; set; }
        public String fech_a { get; set; }
    }
}
