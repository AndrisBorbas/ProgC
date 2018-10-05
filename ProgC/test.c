// ***********************************************************************
// Assembly         :
// Author           : cxl20
// Created          : 09-27-2018
//
// Last Modified By : cxl20
// Last Modified On : 09-28-2018
// ***********************************************************************
// <copyright file="test.c" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include <stdio.h>

/// <summary>
/// Tests this instance.
/// </summary>
void test() {
	char str1[20], str2[30];

	printf("Enter name: ");
	scanf("%s", str1);

	printf("Enter your website name: ");
	scanf("%s", str2);

	printf("Entered Name: %s\n", str1);
	printf("Entered Website:%s", str2);
}
