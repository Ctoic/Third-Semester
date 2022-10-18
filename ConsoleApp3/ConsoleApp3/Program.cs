using ConsoleApp3;

MenuItem m = new MenuItem(1 , "Pizza" , "Fajita " , 1000 , 100);
MenuItem m1 = new MenuItem(2, "Pasta", "Creami ", 100, 100);
MenuItem m2 = new MenuItem(3, "Chiken Biryani", "Chiken Biryani ", 10000, 100);
MenuItem m3 = new MenuItem(4, "Pizza", "Fajita ", 100, 100);
MenuItem m4 = new MenuItem(5, "Pizza", "Fajita ", 100, 100);

Bill b = new Bill(1);
Menu Menu = new Menu();
Menu.addTomenu(m);
Menu.addTomenu(m1);
Menu.addTomenu(m2);
Menu.addTomenu(m3);
Menu.addTomenu(m4);


Menu.display();

while (true)
{ Console.WriteLine("Enter Item Id or 0 to Exit");
    int ch = Convert.ToInt32(Console.ReadLine());
    if (ch == 0)
    {
        break;
    }
    MenuItem o = Menu.ifExist(ch);
    if(o != null)
    {
        Console.Write("ENter Quantity");
        int qty = Convert.ToInt32(Console.ReadLine());
        o.Quantity = qty;
        b.AddtOorder(o);
    }
}


b.Display();


b.CalculateBill();
