using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SotnikovOOP5
{
    class Program
    {
        public static void Menu()
        {
            string s = @"Welcome back! Choose the action: 
    1. Add station
    2. Show stations
    3. Delete station
    4. Clear system
    5. Load from file
    6. Save to file
    0. Exit
    ";

            Console.WriteLine(s);
        }

        static void Main(string[] args)
        {
            SotnikovMetroSys MetroSys = new SotnikovMetroSys();

            while(true)
            {
                Menu();
                int choose = int.Parse(Console.ReadLine());
                Console.WriteLine();

                switch (choose)
                {
                    case 1:
                        {
                            string s = @"What to add?
    1. Station
    2. Tech Station
    ";
                            Console.WriteLine(s);

                            int i = int.Parse(Console.ReadLine());
                            Console.WriteLine();
                            MetroSys.Add(i);
                            break;
                        }
                    case 2:
                        {
                            MetroSys.ShowAll();
                            break;
                        }
                    case 3:
                        {
                            Console.WriteLine("Enter ID of station: ");
                            int i = int.Parse(Console.ReadLine());
                            Console.WriteLine();
                            MetroSys.DeleteOne(i);
                            break;
                        }
                    case 4:
                        {
                            MetroSys.DeleteAll();
                            break;
                        }
                    case 5:
                        {
                            MetroSys.Load();
                            break;
                        }
                    case 6:
                        {
                            MetroSys.Save();
                            break;
                        }
                    default:
                        {
                            return;
                        }
                }
            }
            // Console.ReadKey();
        }
    }
}
