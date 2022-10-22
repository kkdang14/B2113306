package THBUOI4;

import java.util.Scanner;

public abstract class ConVat {
	private String specimen;
	private String feacolor;
	private int weight;
	
	ConVat(){
		specimen = new String();
		feacolor = new String();
		weight = 0;
	}
	
	public ConVat(String specimen, String feacolor, int weight){
		this.specimen = specimen;
		this.feacolor = feacolor;
		this.weight = weight;
	}
	
	public ConVat(ConVat ani) {
		specimen = new String(ani.specimen);
		feacolor = new String(ani.feacolor);
		weight = ani.weight;
	}
	
	public abstract void Keu();
	
	public void nhapThongTin() {
		Scanner s = new Scanner(System.in);
		System.out.println("Nhập tên giống : ");
		specimen = s.nextLine();
		System.out.println("Nhập màu lông: ");
		feacolor = s.nextLine();
		System.out.println("Nhập cân nặng: ");
		weight = s.nextInt();
	}
	
	public void hienThi() {
		System.out.println("+ Giống: " + specimen);
		System.out.println("+ Màu lông: "+ feacolor);
		System.out.println("+ Cân năng: "+ weight +" Kg");
	}
	
}
