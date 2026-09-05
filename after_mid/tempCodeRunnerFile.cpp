void ForwardElimination()
// {
//     double pivot;
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = i + 1; j < n; j++)
//         {
//             pivot = a[j][i] / a[i][i];
//             for(int k = i; k < n; k++)
//             {
//                 a[j][k] = a[j][k]- pivot * a[i][k];
//             }
//             b[j] = b[j] - pivot * b[i];
//         }
//     }
// }