using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;


namespace SotnikovOOP5
{
    [Serializable]
    class SotnikovMetroSys
    {
        protected List<SotnikovStation> MetroSys = new List<SotnikovStation>();

        public void Add(int type)
        {
            switch(type)
            {
                case 1:
                    {
                        SotnikovStation s = new SotnikovStation();
                        s.Console_in();
                        MetroSys.Add(s);
                        break;
                    }
                case 2:
                    {
                        SotnikovTechStation s = new SotnikovTechStation();
                        s.Console_in();
                        MetroSys.Add(s);
                        break;
                    }
                default:
                    {
                        break;
                    }
            }

            Console.WriteLine("Added.\n");
        }

        public void ShowAll()
        {
            if (MetroSys.Count != 0)
            {

                Console.WriteLine("List of stations: \n");

                foreach (SotnikovStation s in MetroSys)
                {
                    s.Console_out();
                    Console.WriteLine("\n");
                }
            }
            else Console.WriteLine("Empty list.\n");
        }

        public void DeleteAll()
        {
            if (MetroSys.Count != 0)
            {
                MetroSys.Clear();
                Console.WriteLine("Cleared.\n");
            }
            else Console.WriteLine("Nothing to delete.\n");
        }

        public void DeleteOne(int i)
        {
            var removeItem = MetroSys.Single(s => s.id == i);
            MetroSys.Remove(removeItem);
            Console.WriteLine("Deleted.\n");
        }

        public void Save()
        {
            Console.WriteLine("Enter the name for output file: ");
            string s = Console.ReadLine();

            Stream f = File.Create(s);
            BinaryFormatter serial = new BinaryFormatter();
            serial.Serialize(f, MetroSys);
            f.Close();
            Console.WriteLine("Saved.\n");
        }

        public void Load()
        {
            Console.WriteLine("Enter the name for input file: ");
            string s = Console.ReadLine();

            Stream f = File.OpenRead(s);
            BinaryFormatter deserial = new BinaryFormatter();
            MetroSys = deserial.Deserialize(f) as List<SotnikovStation>;
            f.Close();
            Console.WriteLine("Loaded.\n");
        }
    }
}
