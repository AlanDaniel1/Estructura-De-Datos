using System;
using System.Collections.Generic;

public class Cliente
{
    public string Nombre { get; set; }
    public int Id { get; set; }

    public Cliente(string nombre, int id)
    {
        Nombre = nombre;
        Id = id;
    }

    public override string ToString()
    {
        return $"Cliente: {Nombre}, ID: {Id}";
    }
}

public class SistemaAtencionClientes
{
    private Queue<Cliente> colaClientes;

    public SistemaAtencionClientes()
    {
        colaClientes = new Queue<Cliente>();
    }

    // Agregar nuevo cliente a la cola
    public void AgregarCliente(Cliente cliente)
    {
        colaClientes.Enqueue(cliente);
        Console.WriteLine($"{cliente.Nombre} ha sido agregado a la cola.");
    }

    // Atender al siguiente cliente en la cola
    public void AtenderCliente()
    {
        if (colaClientes.Count > 0)
        {
            Cliente clienteAtendido = colaClientes.Dequeue();
            Console.WriteLine($"{clienteAtendido.Nombre} está siendo atendido.");
        }
        else
        {
            Console.WriteLine("No hay clientes en la cola.");
        }
    }

    // Mostrar estado actual de la cola
    public void MostrarEstadoCola()
    {
        if (colaClientes.Count > 0)
        {
            Console.WriteLine("Estado actual de la cola:");
            foreach (var cliente in colaClientes)
            {
                Console.WriteLine(cliente);
            }
        }
        else
        {
            Console.WriteLine("La cola está vacía.");
        }
    }
}

public class Program
{
    public static void Main()
    {
        SistemaAtencionClientes sistema = new SistemaAtencionClientes();
        
        // Agregar algunos clientes a la cola
        sistema.AgregarCliente(new Cliente("Carlos", 1));
        sistema.AgregarCliente(new Cliente("Ana", 2));
        sistema.AgregarCliente(new Cliente("Luis", 3));
        
        // Mostrar el estado actual de la cola
        sistema.MostrarEstadoCola();
        
        // Atender a los clientes en el orden en que llegaron
        sistema.AtenderCliente();
        sistema.AtenderCliente();
        
        // Mostrar el estado actual de la cola
        sistema.MostrarEstadoCola();
        
        // Atender al siguiente cliente
        sistema.AtenderCliente();
        sistema.AtenderCliente(); // Intentar atender cuando la cola está vacía
    }
}
