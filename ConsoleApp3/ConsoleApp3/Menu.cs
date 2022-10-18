using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class Menu
    {
        List<MenuItem> menuItems = new List<MenuItem>();

        public void addTomenu(MenuItem item)
        {
            menuItems.Add(item);
        }

        public void display()
        {
            foreach (MenuItem item in menuItems)
            {
               Console.WriteLine(item.Id + "\t\t" + item.Name + "\t\t" + item.Description +"\t\t" + item.Price + "\t\t" + item.Quantity);
            }
        }

        public MenuItem ifExist(int id)
        {
            foreach (MenuItem item in menuItems)
                if (item.Id == id)
                    return item;

                
            return null;
        }
    }
}
