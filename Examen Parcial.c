using System;
using System.Collections.Generic;

class Program
{
    static List<int> lista = new List<int>();

    static void Main(string[] args)
    {
        bool continuar = true;

        while (continuar)
        {
            MostrarMenu();
            string v = Console.ReadLine();
            string opcion = v;

            switch (opcion)
            {
                case "1":
                    AgregarElemento();
                    break;
                case "2":
                    EliminarElemento();
                    break;
                case "3":
                    MostrarLista();
                    break;
                case "4":
                    continuar = false;
                    break;
                default:
                    Console.WriteLine("Opción no válida, por favor intenta de nuevo.");
                    break;
            }
        }

        Console.WriteLine("Gracias por usar el programa. ¡Adiós!");
    }

    static void MostrarMenu()
    {
        Console.WriteLine("\nMenú:");
        Console.WriteLine("1. Agregar elemento");
        Console.WriteLine("2. Eliminar elemento");
        Console.WriteLine("3. Mostrar lista");
        Console.WriteLine("4. Salir");
        Console.Write("Selecciona una opción: ");
    }

    static void AgregarElemento()
    {
        Console.Write("Ingresa el valor a añadir: ");
        if (int.TryParse(Console.ReadLine(), out int valor))
        {
            lista.Add(valor);
            Console.WriteLine("Elemento añadido.");
        }
        else
        {
            Console.WriteLine("Valor no válido, por favor ingresa un número.");
        }
    }

    static void EliminarElemento()
    {
        Console.Write("Ingresa el valor a eliminar: ");
        if (int.TryParse(Console.ReadLine(), out int valor))
        {
            if (lista.Remove(valor))
            {
                Console.WriteLine("Elemento eliminado.");
            }
            else
            {
                Console.WriteLine("El valor no se encontró en la lista.");
            }
        }
        else
        {
            Console.WriteLine("Valor no válido, por favor ingresa un número.");
        }
    }

    static void MostrarLista()
    {
        if (lista.Count > 0)
        {
            Console.WriteLine("Elementos en la lista:");
            foreach (int elemento in lista)
            {
                Console.WriteLine(elemento);
            }
        }
        else
        {
            Console.WriteLine("La lista está vacía.");
        }
    }
}
