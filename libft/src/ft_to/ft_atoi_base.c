// // char	ft_atoi_base(int input, int base_system, char format)
// // {
// // 	char	*return_value;

// // 	if (input >= base_system)
// // 	{
// // 		return_value[counter](input / base_system, base_system, format);
// // 		counter++;
// // 		return_value[counter](input % base_system, base_system, format);
// // 	}
// // 	else
// // 	{
// // 		if (input <= 9)
// // 		{
// // 			return_value[counter] = (input + '0');
// // 		}
// // 		else
// // 		{
// // 			if (format == 'x')
// // 				return_value[counter] = (input - 10 + 'a');
// // 			if (format == 'X')
// // 				return_value[counter] = (input - 10 + 'A');
// // 		}
// // 		counter++;
// // 	}
// // }

// #include <stdio.h>
// char	*ft_atoi_base(int input, int base_system, char format)
// {
// 	static int counter = 0;
// 	if (input >= base_system)
// 		ft_atoi_base(input / base_system, base_system, format);
// 	if (input <= 9)
// 		return_value[counter] = (input + '0');
// 	else
// 	{
// 		if (format >= 'a' && format <= 'z')
// 			return_value[counter] = (input - 10 + 'a');
// 		if (format >= 'A' && format <= 'Z')
// 			return_value[counter] = (input - 10 + 'A');
// 	}
// 	counter++;
// 	return_value[counter] = '\0'; // Null-terminate the string
// 	return return_value;
// }

// int	main(void)
// {
// 	char	*number = ft_atoi_base(150, 16, 'A');
// 	printf("%s", number);
// 	return (0);
// }
