using System;
using System.Collections.Generic;

namespace TorresDeHanoi
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Ingresa el número de discos: ");
            int numDiscos = int.Parse(Console.ReadLine());

            Stack<int> torreA = new Stack<int>();
            Stack<int> torreB = new Stack<int>();
            Stack<int> torreC = new Stack<int>();

            for (int i = numDiscos; i >= 1; i--)
            {
                torreA.Push(i);
            }

            MostrarTorres(numDiscos, torreA, torreB, torreC);

            Console.WriteLine("Resolviendo Torres de Hanoi...\n");
            ResolverHanoi(numDiscos, torreA, torreB, torreC);

            Console.WriteLine("Juego resuelto!");
        }

        static void MostrarTorres(int numDiscos, Stack<int> torreA, Stack<int> torreB, Stack<int> torreC)
        {
            Console.WriteLine("Torre A: " + string.Join(", ", torreA));
            Console.WriteLine("Torre B: " + string.Join(", ", torreB));
            Console.WriteLine("Torre C: " + string.Join(", ", torreC));
            Console.WriteLine();
        }

        static void ResolverHanoi(int numDiscos, Stack<int> origen, Stack<int> auxiliar, Stack<int> destino)
        {
            if (numDiscos == 1)
            {
                destino.Push(origen.Pop());
                MostrarTorres(numDiscos, origen, auxiliar, destino);
            }
            else
            {
                ResolverHanoi(numDiscos - 1, origen, destino, auxiliar);
                destino.Push(origen.Pop());
                MostrarTorres(numDiscos, origen, auxiliar, destino);
                ResolverHanoi(numDiscos - 1, auxiliar, origen, destino);
            }
        }
    }
}
