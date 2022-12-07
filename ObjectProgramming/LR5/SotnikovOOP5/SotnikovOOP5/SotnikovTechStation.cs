using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotnikovOOP5
{
    [Serializable]
    class SotnikovTechStation : SotnikovStation
    {
        protected int category;

        public override void Console_in()
        {
            base.Console_in();

            Console.Write("Category: ");
            category = int.Parse(Console.ReadLine());
        }

        public override void Console_out()
        {
            base.Console_out();

            Console.WriteLine("Category: " + category);
        }
    }
}
