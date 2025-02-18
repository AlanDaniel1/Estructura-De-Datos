using System;

public class Nodo
{
    public int Valor { get; set; }
    public Nodo Siguiente { get; set; }
    public Nodo Anterior { get; set; }

    public Nodo(int valor)
    {
        Valor = valor;
        Siguiente = null;
        Anterior = null;
    }
}

public class ListaDoblementeEnlazada
{
    private Nodo cabeza;
    private Nodo cola;

    public ListaDoblementeEnlazada()
    {
        cabeza = null;
        cola = null;
    }

    public void InsertarAlInicio(int valor)
    {
        Nodo nuevoNodo = new Nodo(valor);
        if (cabeza == null)
        {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else
        {
            nuevoNodo.Siguiente = cabeza;
            cabeza.Anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    public void InsertarAlFinal(int valor)
    {
        Nodo nuevoNodo = new Nodo(valor);
        if (cabeza == null)
        {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else
        {
            cola.Siguiente = nuevoNodo;
            nuevoNodo.Anterior = cola;
            cola = nuevoNodo;
        }
    }

    public void MostrarLista()
    {
        Nodo actual = cabeza;
        while (actual != null)
        {
            Console.Write(actual.Valor + " ");
            actual = actual.Siguiente;
        }
        Console.WriteLine();
    }

    public void MostrarListaInversa()
    {
        Nodo actual = cola;
        while (actual != null)
        {
            Console.Write(actual.Valor + " ");
            actual = actual.Anterior;
        }
        Console.WriteLine();
    }

    public void EliminarNodo(int valor)
    {
        Nodo actual = cabeza;
        while (actual != null)
        {
            if (actual.Valor == valor)
            {
                if (actual == cabeza)
                {
                    cabeza = actual.Siguiente;
                    if (cabeza != null)
                    {
                        cabeza.Anterior = null;
                    }
                }
                else if (actual == cola)
                {
                    cola = actual.Anterior;
                    if (cola != null)
                    {
                        cola.Siguiente = null;
                    }
                }
                else
                {
                    actual.Anterior.Siguiente = actual.Siguiente;
                    actual.Siguiente.Anterior = actual.Anterior;
                }
                break;
            }
            actual = actual.Siguiente;
        }
    }
}

public class Program
{
    public static void Main()
    {
        ListaDoblementeEnlazada lista = new ListaDoblementeEnlazada();
        lista.InsertarAlInicio(10);
        lista.InsertarAlInicio(20);
        lista.InsertarAlFinal(30);
        lista.InsertarAlFinal(40);
        
        Console.WriteLine("Lista:");
        lista.MostrarLista();
        
        Console.WriteLine("Lista en orden inverso:");
        lista.MostrarListaInversa();
        
        lista.EliminarNodo(20);
        Console.WriteLine("Lista después de eliminar 20:");
        lista.MostrarLista();
    }
}
