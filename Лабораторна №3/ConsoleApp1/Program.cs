using System;

public class Room
{
    private double area; // метраж
    private double ceilingHeight; // висота стелі
    private int numberOfWindows; // кількість вікон

    // Конструктор класу, що ініціалізує поля
    public Room(double area, double ceilingHeight, int numberOfWindows)
    {
        if (area <= 0)
        {
            throw new ArgumentException("Footage of the room must be higher than 0.", nameof(area));
        }

        if (ceilingHeight <= 0)
        {
            throw new ArgumentException("Ceiling height must be higher than 0.", nameof(ceilingHeight));
        }

        if (numberOfWindows < 0)
        {
            throw new ArgumentException("Number of windows must be higher than 0.", nameof(numberOfWindows));
        }

        this.area = area;
        this.ceilingHeight = ceilingHeight;
        this.numberOfWindows = numberOfWindows;
    }

    // Властивість для отримання стану об’єкта
    public double Area
    {
        get { return area; }
    }

    public double CeilingHeight
    {
        get { return ceilingHeight; }
    }

    public int NumberOfWindows
    {
        get { return numberOfWindows; }
    }

    // Метод для обчислення площі кімнати
    public double CalculateArea()
    {
        return area;
    }

    // Метод для обчислення об'єму кімнати
    public double CalculateVolume()
    {
        return area * ceilingHeight;
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        try
        {
            Room room1 = new Room(20, 3, 2);
            Console.WriteLine("Room 1:");
            Console.WriteLine("Footage: " + room1.Area + " sqm");
            Console.WriteLine("Ceiling height: " + room1.CeilingHeight + " m");
            Console.WriteLine("Number of windows: " + room1.NumberOfWindows);
            Console.WriteLine("Area of the room: " + room1.CalculateArea() + " sqm");
            Console.WriteLine("Volume of the room: " + room1.CalculateVolume() + " cubm");
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }

        try
        {
            Room room2 = new Room(10, 3, 5);
            Console.WriteLine("Room 2:");
            Console.WriteLine("Footage: " + room2.Area + " sqm");
            Console.WriteLine("Ceiling height: " + room2.CeilingHeight + " m");
            Console.WriteLine("Number of windows: " + room2.NumberOfWindows);
            Console.WriteLine("Area of the room: " + room2.CalculateArea() + " sqm");
            Console.WriteLine("Volume of the room: " + room2.CalculateVolume() + " cubm");
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}
