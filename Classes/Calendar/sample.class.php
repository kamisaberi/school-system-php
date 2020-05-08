<?
include('persian_date.class.php');
$persian=new persian_date();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD Xhtml 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd"> 
<html xmlns="http://www.w3.org/1999/xhtml">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style>
body,table,tr,td{
font-family:tahoma;
font-size:12px;
}


<?php
include 'JalaliGregorianCalendar.inc';
$persian =new persian_date();
?>
</style>
</head>
	<div align="center">
		<table width="500" cellpadding="5"  cellspacing="0" dir="rtl"  bordercolordark="#FFFFFF" bordercolorlight="#000800" border="1">
			<tr align="center">
				<td><b>&#1583;&#1587;&#1578;&#1608;&#1585;</b></td>
				<td><b>&#1582;&#1585;&#1608;&#1580;&#1740; &#1606;&#1605;&#1575;&#1740;&#1588; &#1578;&#1575;&#1585;&#1740;&#1582;</b></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('Y')</td>
				 <td dir="ltr"><?=$persian->date('Y');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('y')</td>
				<td dir="ltr"><?=$persian->date('y');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('M')</td>
				<td dir="ltr"><?=$persian->date('M');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('m')</td>
				<td dir="ltr"><?=$persian->date('m');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('D')</td>
				<td dir="ltr"><?=$persian->date('D');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('d')</td>
				<td dir="ltr"><?=$persian->date('d');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('Ymd')</td>
				<td dir="ltr"><?=$persian->date('Ymd');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('compelete')</td>
				<td dir="ltr"><?=$persian->date('compelete');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date('Y/m/d')</td>
				<td dir="ltr"><?=$persian->date('Y/m/d');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">to_date('1983-03-20','Y/m/d');</td>
				<td dir="ltr"><?=$persian->to_date('1983-03-20','Y/m/d');?></td>
			</tr>
			<tr align="center">
				<td dir="ltr">date_to('1364/02/06')</td>
				<td dir="ltr"><?=$persian->date_to('1364/02/06');?></td>
			</tr>
		</table>
	</div>
</html>