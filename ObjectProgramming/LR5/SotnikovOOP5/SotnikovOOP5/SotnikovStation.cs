using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotnikovOOP5
{
    [Serializable]
    class SotnikovStation
    {
        protected string name;
        public int id;
        protected int line;

        public virtual void Console_in()
        {
            Console.Write("Ready to read station's properties.\n");

            Console.Write("ID: ");
            id = int.Parse(Console.ReadLine());

            Console.Write("Name: ");
            name = Console.ReadLine();

            Console.Write("Line: ");
            line = int.Parse(Console.ReadLine());
        }

        public virtual void Console_out()
        {
            Console.WriteLine("ID: " + id);
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Line: " + line);
        }
    }
}
