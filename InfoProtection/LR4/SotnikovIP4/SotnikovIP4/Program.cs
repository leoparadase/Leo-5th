using System;
using Microsoft.Data.Sqlite;

namespace SotnikovIP4
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var db = new SqliteConnection("Data Source=db.sqlite"))
            {
                db.Open();
                var dbc = db.CreateCommand();

               

                while (true)
                {
                    Console.WriteLine("Choose the action:\n");
                    Console.WriteLine("1. Show all");
                    Console.WriteLine("2. Show one -- unsafe method");
                    Console.WriteLine("3. Show one -- safe method");
                    Console.WriteLine("4. Generate database");
                    Console.WriteLine("0. Exit");

                    int a = int.Parse(Console.ReadLine());
                    switch (a)
                    {
                        case 1:
                            {
                                dbc.CommandText = "SELECT txt FROM test";
                                dbc.ExecuteNonQuery();
                                SqliteDataReader reader = dbc.ExecuteReader();
                                while (reader.Read())
                                    Console.WriteLine("{0}", reader.GetString(0));
                                reader.Close();
                                break;
                            }
                        case 2:
                            {
                                Console.WriteLine("\nInput object name:");
                                string b = Console.ReadLine();

                                dbc.CommandText = $"SELECT int FROM test WHERE txt = '{b}'";
                                dbc.ExecuteNonQuery();

                                SqliteDataReader reader = dbc.ExecuteReader();
                                while (reader.Read())
                                    Console.WriteLine("{0}", reader.GetString(0));
                                reader.Close();
                                break;
                            }
                        case 3:
                            {
                                Console.WriteLine("\nInput object name:");
                                string b = Console.ReadLine();

                                using (SqliteCommand command = new SqliteCommand("select int from test where txt like @object", db))
                                {
                                    command.Parameters.AddWithValue("@object", b);
                                    var output = command.ExecuteScalar();
                                    if (output == null)
                                        Console.WriteLine("No such object");
                                    else
                                        Console.WriteLine(output);
                                }
                                break;
                            }
                        case 4:
                            {
                                dbc.CommandText = $"DROP TABLE IF EXISTS test";
                                dbc.ExecuteNonQuery();

                                dbc.CommandText = @" CREATE TABLE IF NOT EXISTS test(
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    txt TEXT,
                    int INTEGER)";
                                dbc.ExecuteNonQuery();
                                for (var i = 0; i < 10; i++)
                                {
                                    dbc.CommandText = $"INSERT INTO test VALUES (NULL, 'test{i}', {i * 2})";
                                    dbc.ExecuteNonQuery();
                                }
                                break;
                            }
                        default:
                            { return; }
                    }
                }
            }
        }
    }
}
