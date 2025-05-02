using System.Globalization;
using System.Text;

namespace Console_labyrinth
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;

            Thread.CurrentThread.CurrentCulture = new CultureInfo("uk-UA");
            Thread.CurrentThread.CurrentUICulture = new CultureInfo("uk-UA");

            Console.WriteLine("Hello, World!");
            labyrinth.Ran();
        }
    }
}
