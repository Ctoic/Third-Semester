using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class Bill
    {
        List<MenuItem> orders = new List<MenuItem>();
        public int Id { get; set; }
        public Bill(int id)
        {
            Id = id;
        }
        public void Display()
        {
            foreach (MenuItem item in orders)
            {
                Console.WriteLine(item.Id + "\t\t" + item.Name + "\t\t" + item.Price + "\t\t" + item.Quantity);
            }
        }

        public void AddtOorder(MenuItem itrem)
        {
            orders.Add(itrem);
        }

        public void CalculateBill()
        {
            double subtotal = 0;
            double total = 0;
            foreach(MenuItem menuItem in orders)
            {
                subtotal = subtotal + menuItem.Quantity * menuItem.Price;

            }

            double gst = subtotal * 0.17;
            total = gst + subtotal;

            Console.WriteLine(Id);
            Console.WriteLine(gst);
            Console.WriteLine(total);
            

        }
    }
}
