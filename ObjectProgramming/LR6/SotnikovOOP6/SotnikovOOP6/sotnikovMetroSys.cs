using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Collections;


namespace SotnikovOOP6
{
    [Serializable]
    class sotnikovMetroSys
    {
        public static ArrayList stations = new ArrayList();

        public static void AddStation(sotnikovStation s)
        {
            stations.Add(s);
        }
        public sotnikovStation GetElement(int cur_index)
        {
            sotnikovStation cur;
            if (stations[cur_index].GetType() == typeof(sotnikovStation))
            {
                cur = new sotnikovStation();
                cur = (sotnikovStation)stations[cur_index];
            }
            else
            {
                cur = new sotnikovTechStation();
                cur = (sotnikovTechStation)stations[cur_index];
            }

            return cur;
        }
        public bool GetElementType(int cur_index)
        {
            if (stations[cur_index].GetType() == typeof(sotnikovStation))
            {
                return false;
            }
            else
                return true;
        }
        public void Delete(int index)
        {
            stations.RemoveAt(index);
        }
    }
}
