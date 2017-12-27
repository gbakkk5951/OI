  /// �볲����
        /// </summary>
        /// <param name="unsorted">��������</param>
        /// <param name="maxNumber">���������е������,�������ָ���Ļ�</param>
        /// <returns></returns>
        static int[] pogeon_sort(int[] unsorted, int maxNumber = 10)
        {
            int[] pogeonHole = new int[maxNumber + 1];
            foreach (var item in unsorted)
            {
                pogeonHole[item]++;
            }
            return pogeonHole;
            /*
             * pogeonHole[10] = 4; �ĺ�����
             * �ڴ�����������4��10����,ͬ������
             */
        }

        static void Main(string[] args)
        {
            int[] x = { 99, 65, 24, 47, 47, 50, 99, 88, 66, 33, 66, 67, 31, 18, 24 };
            var sorted = pogeon_sort(x, 99);
            for (int i = 0; i < sorted.Length; i++)
            {
                for (int j = 0; j < sorted[i]; j++)
                {
                    Console.WriteLine(i);
                }
            }
            Console.ReadLine();
        }
