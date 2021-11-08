create database QLNV
go
use QLNV
go
create table NhanVien
(
   MaNV char(5),
   TenNV nvarchar(20),
   NgaySinh datetime,
   MaNVQL char(5)
   primary key (MaNV)
)
go
create table DuAn
(
   MaDA char(5),
   TenDA nvarchar(20),
   MaNVChuTri char(5)
   primary key (MaDA)
)
go
create table ThamGiaDuAn
(
    MaNV char(5),
	MaDA char(5),
	SoGio int
	primary key (MaNV,MADa)
)
go
alter table ThamGiaDuAn 
add 
    constraint FK_ThamGiaDuAn_DuAn 
    foreign key (MaDA) 
    references DuAn (MaDA)
go
alter table ThamGiaDuAn 
add 
    constraint FK_ThamGiaDuAn_NhanVien 
    foreign key (MaNV) 
	references NhanVien (MaNV)
go
alter table DuAn 
add 
    constraint FK_DuAn_NhanVien 
    foreign key (MaNVChuTri) 
	references NhanVien (MaNV)
go
alter table NhanVien 
add 
    constraint FK_NhanVien_NhanVien 
	foreign key (MaNVQL) 
	references NhanVien (MaNV)
go
insert into NhanVien(MaNV, TenNV, NgaySinh, MaNVQL) 
 values ('NV1',N'Nguyễn Văn A','5/20/1999',NULL)
insert into NhanVien(MaNV, TenNV, NgaySinh, MaNVQL) 
 values ('NV2',N'Nguyễn Văn B','3/2/1999',NULL)
insert into DuAn(MaDA, TenDA, MaNVChuTri)
 values ('DA1',N'Web bán hàng','NV1')
insert into DuAn(MaDA, TenDA, MaNVChuTri)
 values ('DA2',N'App bán hàng','NV2')
insert into ThamGiaDuAn(MaNV, MaDA, SoGio)
 values ('NV1','DA1',30)
insert into ThamGiaDuAn(MaNV, MaDA, SoGio)
 values ('NV2','DA2',60)
update NhanVien set MaNVQL='NV2'
where MaNV='NV1'
update NhanVien set MaNVQL='NV2'
where MaNV='NV2'

select * from NhanVien
select * from DuAn
select * from ThamGiaDuAn
