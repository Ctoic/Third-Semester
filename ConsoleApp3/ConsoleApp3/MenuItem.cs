using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp3
{
    internal class MenuItem
    {
        public int Id;
        public string Name { get; set; }
        public string Description { get; set; }

        public double  Price { get; set; }

        public int Quantity { get; set; }

        public MenuItem(int id , string name , string desc , double price , int qty)
        {
            Id = id;
            Name = name;
            Description = desc;
            Price = price;
            Quantity = qty;
        }

        



    }
}
