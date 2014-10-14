using System;
using System.Collections.Generic;

namespace OrderProcessing
{
    class Order
    {
        public int CustomerId { get; set; }
        public string ProductName { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Order> orders = new List<Order>();
            for (int i = 0; i < 100; ++i)
            {
                orders.Add(new Order
                {
                    CustomerId = i,
                    ProductName = "Product #" + i
                });
            }
            Console.ReadLine();
            GC.KeepAlive(orders);
        }
    }
}
