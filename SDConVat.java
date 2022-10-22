package THBUOI4;

import java.util.Scanner;
import java.util.Random;

public class SDConVat{
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		ConVat A[];
		int i,n;
		System.out.println("Nhập số con vật: ");
		n=s.nextInt();
		A = new ConVat[n];
		for(i=0; i<n; i++) {
			Random rd= new Random();
			int a= rd.nextInt(5);
			if(a == 1)
				A[i] = new Bo();
			else if (a == 2)
				A[i] = new Heo();
			else if(a == 3)
				A[i] = new De();
			else A[i] = new Ga();
			A[i].nhapThongTin();
		}
		
		for(i=0; i<n; i++) {
			System.out.println("<<=====================>>");
			A[i].hienThi();
			A[i].Keu();
		}
		System.out.println("<<=====================>>");
	}	
}
