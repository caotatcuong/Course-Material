create database QuanLyChuyenBay
go
use QuanLyChuyenBay
go
create table KHACHHANG
(
     MAKH char(15),
	 TEN varchar(15),
	 DCHI varchar(50),
	 DTHOAI char(12)
	 PRIMARY KEY(MAKH)
)
create table NHANVIEN
(
     MANV char(15),
	 TEN varchar(15),	
     DCHI varchar(50),	
     DTHOAI char(12),	
     LUONG float,	
     LOAINV bit
     PRIMARY KEY(MANV)
)
create table LOAIMB
(
     MALOAI char(15),	
     HANGSX char(15)
     PRIMARY KEY(MALOAI)
)
create table MAYBAY
(
     SOHIEU int,	
     MALOAI char(15)
     PRIMARY KEY(SOHIEU,MALOAI)
)
create table CHUYENBAY
(
    MACB char(4),	
    SBDI char(3),	
    SBDEN char(3),	
    GIODI time,	
    GIODEN time
    PRIMARY KEY(MACB)
)
create table LICHBAY
(
    NGAYDI datetime,	
    MACB char(4),	
    SOHIEU int,	
    MALOAI char(15)
    PRIMARY KEY(NGAYDI, MACB)
)
create table DATCHO
(
    MAKH char(15),	
    NGAYDI datetime,	
    MACB char(4)
    PRIMARY KEY(MAKH, NGAYDI, MACB)
)
create table KHANANG
(
    MANV char(15),	
    MALOAI char(15)
    PRIMARY KEY(MANV, MALOAI)
)
create table PHANCONG
(
    MANV char(15),	
    NGAYDI datetime,	
    MACB char(4)
    PRIMARY KEY(MANV, NGAYDI, MACB)
)
go
alter table DATCHO add
    constraint FK_DATCHO_KHACHHANG foreign key (MAKH) references KHACHHANG (MAKH),
	constraint FK_DATCHO_LICHBAY foreign key (NGAYDI, MACB) references LICHBAY (NGAYDI, MACB)

alter table LICHBAY add
    constraint FK_LICHBAY_CHUYENBAY foreign key (MACB) references CHUYENBAY (MACB),
	constraint FK_LICHBAY_MAYBAY foreign key (SOHIEU, MALOAI) references MAYBAY (SOHIEU, MALOAI)

alter table MAYBAY add
    constraint FK_MAYBAY_LOAIMB foreign key (MALOAI) references LOAIMB (MALOAI)

alter table KHANANG add
    constraint FK_KHANANG_LOAIMB foreign key (MALOAI) references LOAIMB (MALOAI),
	constraint FK_KHANANG_NHANVIEN foreign key (MANV) references NHANVIEN (MANV)

alter table PHANCONG add
    constraint FK_PHANCONG_NHANVIEN foreign key (MANV) references NHANVIEN (MANV),
	constraint FK_PHANCONG_LICHBAY foreign key (NGAYDI, MACB) references LICHBAY (NGAYDI, MACB)
go
insert into NHANVIEN values('1006','Chi','12/6 Nguyen Kiem','8120012',150000,'0')
insert into NHANVIEN values('1005','Giao','65 Nguyen Thai Son','8324467',500000,'0')
insert into NHANVIEN values('1001','Huong','8 Dien Bien Phu','8330733',500000,'1')
insert into NHANVIEN values('1002','Phong', '1	Ly Thuong Kiet','8308117',450000,'1')
insert into NHANVIEN values('1004','Phuong','351 Lac Long Quan','8308155',250000,'0')
insert into NHANVIEN values('1003','Quang','78 Truong Dinh','8324461',350000,'1')
insert into NHANVIEN values('1007','Tam','36 Nguyen Van Cu','8458188',500000,'0')

insert into KHACHHANG values('0009','Nga','223 Nguyen Trai','8932320')
insert into KHACHHANG values('0101','Anh','567 Tran Phu','8826729')
insert into KHACHHANG values('0045','Thu','285 Le Loi',' 8932203')
insert into KHACHHANG values('0012','Ha','435 Quang Trung','8933232')
insert into KHACHHANG values('0238','Hung','456	Pasteur','9812101')
insert into KHACHHANG values('0397','Thanh','234 Le Van	Si','8952943')
insert into KHACHHANG values('0582','Mai','789 Nguyen Du', NULL)
insert into KHACHHANG values('0934','Minh','678 Le Lai', NULL)
insert into KHACHHANG values('0091','Hai','345 Hung Vuong','8893223')
insert into KHACHHANG values('0314','Phuong','395 Vo Van Tan','8232320')
insert into KHACHHANG values('0613','Vu','348 CMT8','8343232')
insert into KHACHHANG values('0586','Son','123 Bach Dang','8556223')
insert into KHACHHANG values('0422','Tien','75 Nguyen Thong','8332222')

insert into LOAIMB (HANGSX,MALOAI) values('Airbus','A310')
insert into LOAIMB (HANGSX,MALOAI) values('Airbus','A320')
insert into LOAIMB (HANGSX,MALOAI) values('Airbus','A330')
insert into LOAIMB (HANGSX,MALOAI) values('Airbus','A340')
insert into LOAIMB (HANGSX,MALOAI) values('Boeing','B727')
insert into LOAIMB (HANGSX,MALOAI) values('Boeing','B747')
insert into LOAIMB (HANGSX,MALOAI) values('Boeing','B757')
insert into LOAIMB (HANGSX,MALOAI) values('MD','DC10')
insert into LOAIMB (HANGSX,MALOAI) values('MD','DC9')

insert into CHUYENBAY values('100','SLC','BOS','08:00','17:50')
insert into CHUYENBAY values('112','DCA','DEN','14:00','18:07')
insert into CHUYENBAY values('121','STL','SLC','07:00','09:13')
insert into CHUYENBAY values('122','STL','YYV','08:30','10:19')
insert into CHUYENBAY values('206','DFW','STL','09:00','11:40')
insert into CHUYENBAY values('330','JFK','YYV','16:00','18:53')
insert into CHUYENBAY values('334','ORD','MIA','12:00','14:14')
insert into CHUYENBAY values('335','MIA','ORD','15:00','17:14')
insert into CHUYENBAY values('336','ORD','MIA','18:00','20:14')
insert into CHUYENBAY values('337','MIA','ORD','20:30','23:53')
insert into CHUYENBAY values('394','DFW','MIA','19:00','21:30')
insert into CHUYENBAY values('395','MIA','DFW','21:00','23:43')
insert into CHUYENBAY values('449','CDG','DEN','10:00','19:29')
insert into CHUYENBAY values('930','YYV','DCA','13:00','16:10')
insert into CHUYENBAY values('931','DCA','YYV','17:00','18:10')
insert into CHUYENBAY values('932','DCA','YYV','18:00','19:10')
insert into CHUYENBAY values('991','BOS','ORD','17:00','18:22')

insert into KHANANG values('1001','B727')
insert into KHANANG values('1001','B747')
insert into KHANANG values('1001','DC10')
insert into KHANANG values('1001','DC9')
insert into KHANANG values('1002','A320')
insert into KHANANG values('1002','A340')
insert into KHANANG values('1002','B757')
insert into KHANANG values('1002','DC9')
insert into KHANANG values('1003','A310')
insert into KHANANG values('1003','DC9')

insert into MAYBAY values('10','B747')
insert into MAYBAY values('11','B727')
insert into MAYBAY values('13','B727')
insert into MAYBAY values('13','B747')
insert into MAYBAY values('21','DC10')
insert into MAYBAY values('21','DC9')
insert into MAYBAY values('22','B757')
insert into MAYBAY values('22','DC9')
insert into MAYBAY values('23','DC9')
insert into MAYBAY values('24','DC9')
insert into MAYBAY values('70','A310')
insert into MAYBAY values('80','A310')
insert into MAYBAY values('90','B757')

insert into LICHBAY values('11/1/2000','100','80','A310')
insert into LICHBAY values('11/1/2000','112','21','DC10')
insert into LICHBAY values('11/1/2000','206','22','DC9')
insert into LICHBAY values('11/1/2000','334','10','B747')
insert into LICHBAY values('11/1/2000','395','23','DC9')
insert into LICHBAY values('11/1/2000','991','22','B757')
insert into LICHBAY values('11/01/2000','337','10','B747')
insert into LICHBAY values('10/31/2000','100','11','B727')
insert into LICHBAY values('10/31/2000','112','11','B727')
insert into LICHBAY values('10/31/2000','206','13','B727')
insert into LICHBAY values('10/31/2000','334','10','B747')
insert into LICHBAY values('10/31/2000','335','10','B747')
insert into LICHBAY values('10/31/2000','337','24','DC9')
insert into LICHBAY values('10/31/2000','449','70','A310')

insert into DATCHO values('0009','11/01/2000','100')
insert into DATCHO values('0009','10/31/2000','449')
insert into DATCHO values('0045','11/01/2000','991')
insert into DATCHO values('0012','10/31/2000','206')
insert into DATCHO values('0238','10/31/2000','334')
insert into DATCHO values('0582','11/01/2000','991')
insert into DATCHO values('0091','11/01/2000','100')
insert into DATCHO values('0314','10/31/2000','449')
insert into DATCHO values('0613','11/01/2000','100')
insert into DATCHO values('0586','11/01/2000','991')
insert into DATCHO values('0586','10/31/2000','100')
insert into DATCHO values('0422','10/31/2000','449')

insert into PHANCONG values('1001','11/01/2000','100')
insert into PHANCONG values('1001','10/31/2000','100')
insert into PHANCONG values('1002','11/01/2000','100')
insert into PHANCONG values('1002','10/31/2000','100')
insert into PHANCONG values('1003','10/31/2000','100')
insert into PHANCONG values('1003','10/31/2000','337')
insert into PHANCONG values('1004','10/31/2000','100')
insert into PHANCONG values('1004','10/31/2000','337')
insert into PHANCONG values('1005','10/31/2000','337')
insert into PHANCONG values('1006','11/01/2000','991')
insert into PHANCONG values('1006','10/31/2000','337')
insert into PHANCONG values('1007','11/01/2000','112')
insert into PHANCONG values('1007','11/01/2000','991')
insert into PHANCONG values('1007','10/31/2000','206')