<%@LANGUAGE="VBSCRIPT"%>
<!--#include file="../include/costanti.asp"-->
<%

' PhotoAlbum

Dim CurFile, PopFileShowSub, ShowPic, PictureNo
Dim strPathInfo, strPhysicalPath


Dim intTotPics, intPicsPerRow, intPicsPerPage, intTotPages, intPage, strPicArray()
intPicsPerRow  = 4
intPicsPerPage = 8

intPage = CInt(Request.QueryString("Page"))
If intPage = 0 Then
	intPage = 1
End If


CurFile = "DocumentsAlbum.asp"
PopFile = "ShowPicture.asp"
%>
<link rel="stylesheet" type="text/css" href="style.css">
<script language="JavaScript">
<!--
function jumppage(sel) 
{
  var i = sel.selectedIndex
  self.location.href = sel.options[i].value
}
// -->
</script>
<SCRIPT language="javascript">

function setImage(sImageURL)
{
	window.opener.document.Insert.txtURL.value = sImageURL ;
}

function getImage(imageName)
{	
	window.setImage(imageName) ;
	window.close() ;
}
		</SCRIPT>
<script language="JavaScript">
<!-- hide from JavaScript-challenged browsers
function openGalleryWindow(url) {
	if (document.all)
		var xMax = screen.width, yMax = screen.height;
	else
		if (document.layers)
			var xMax = window.outerWidth, yMax = window.outerHeight;
		else
			var xMax = 800, yMax=600;
	var xOffset = (xMax - 200)/2, yOffset = (yMax - 200)/2;
	var xOffset = 100, yOffset = 100;

	popupWin = window.open(url,'new_page','width=700,height=535,screenX='+xOffset+',screenY='+yOffset+',top='+yOffset+',left='+xOffset+',scrollbars=auto,toolbars=no,menubar=no,resizable=yes')
}
// done hiding -->
</script>

<div align="left">
  <table border="0" cellpadding="0" cellspacing="0" style="border-collapse: collapse" bordercolor="#000000" width="100%" id="AutoNumber1">
    <tr> 
      <td align="center"> 
        <table width="100%"  border="0" cellspacing="0" cellpadding="0">
          <tr> 
            <td width="1%"><b><font face="Arial, Helvetica, sans-serif" size="3" color="#25445A"><img src="../images/confida_logo.gif" alt="logo" width="210" height="71"></font></b></td>
            <td align="center" bordercolor="#000000"> 
              <form action=<%=PopFile%> method="POST">
                <font face="Verdana, Arial, Helvetica, sans-serif" size="2"><b>Seleziona 
                il contenitore</b> 
                <select name="go" onChange="jumppage(this);" size=1>
                  <% 
  ShowSub = request("ShowSub")
  ShowPic = request("ShowPic")
  strPathInfo = Request.ServerVariables("PATH_INFO")
  strPhysicalPath = Server.MapPath(strPathInfo)
 
  Set objFSO = CreateObject("Scripting.FileSystemObject")
  Set objFile = objFSO.GetFile(strPhysicalPath)
  Set objFolder = objFile.ParentFolder
  Set objFolderContents = objFolder.Files
  For each Folder in objFolder.SubFolders
  	If Left(Folder.Name,1)<>"_" Then
	  	Response.write "<option "
	  	If ShowSub=Folder.Name Then
	  		Response.Write "selected "
	  	End if
	  	Response.Write"value='" & CurFile & "?ShowSub="
	  	Response.Write(Replace(Folder.Name, " ", "%20"))
	  	response.write "'>"
	  	Response.Write(Folder.Name & "</option>")
	  	If ShowSub <= " " Then
	  	  ShowSub = Folder.Name
		End if
  	End if
  Next 
  Set objFSO = Nothing
  %>
                </select>
                </font> 
              </form>
              <font face="Verdana, Arial, Helvetica, sans-serif" size="2"><br>
              <b>Seleziona la Pagina e clicca sul nome del file</b></font></td>
          </tr>
        </table>
      </td>
    </tr>
  </table>
  <%
If ShowPic > " " then
  ShowPic = Replace(ShowPic, " ", "%20")
  Response.Write "<a href='JavaScript:history.go(-1)'><img src='" & ShowPic & "'><BR><BR><font face=""verdana"" size=""1""><b>Torna Indietro</b></a>"
Else
%>
  <table border="0" cellpadding="0" cellspacing="5" style="border-collapse: collapse" bordercolor="#000000" width="100%" id="AutoNumber1">
    <tr> 
      <%
  strPhysicalPath = Server.MapPath(".\" & ShowSub)
  If ShowSub > " " then
    ShowSub = Replace(ShowSub, " ", "%20")
    Set objFSO = CreateObject("Scripting.FileSystemObject")
    Set objFolder = objFSO.GetFolder(strPhysicalPath)
    Set objFolderContents = objFolder.Files



	 'Get the number of pictures in the subdirectory 
	 intTotPics = 0
    For Each objFileItem in objFolderContents
		'If Ucase(Right(objFileItem.Name,4))=".GIF" OR Ucase(Right(objFileItem.Name,4))=".JPG" THEN
		If Ucase(Right(objFileItem.Name,4))=".TXT" OR Ucase(Right(objFileItem.Name,4))=".XLS" OR Ucase(Right(objFileItem.Name,4))=".PPT" OR Ucase(Right(objFileItem.Name,4))=".PPS" OR Ucase(Right(objFileItem.Name,4))=".DOC" OR Ucase(Right(objFileItem.Name,4))=".PDF" OR Ucase(Right(objFileItem.Name,4))=".ZIP" THEN		
			intTotPics = intTotPics + 1
		End if
    Next

	'Get the total number of pages in the subdirectory 
	If (intTotPics/intPicsPerPage) = (int(intTotPics/intPicsPerPage)) Then
		intTotPages = int(intTotPics/intPicsPerPage)
	Else
		intTotPages = int(intTotPics/intPicsPerPage)+1
	End If
	Redim strPicArray(2,intTotPics)

	'Store picture file names in an array
	x = 0
	For Each objFileItem in objFolderContents
		If Ucase(Right(objFileItem.Name,4))=".TXT" OR Ucase(Right(objFileItem.Name,4))=".XLS" OR Ucase(Right(objFileItem.Name,4))=".PPT" OR Ucase(Right(objFileItem.Name,4))=".PPS" OR Ucase(Right(objFileItem.Name,4))=".DOC" OR Ucase(Right(objFileItem.Name,4))=".PDF" OR Ucase(Right(objFileItem.Name,4))=".ZIP" THEN
			strPicArray(0,x) = objFileItem.Name
			strPicArray(1,x) = Cstr(int(x/intPicsPerPage)+1)
			x = x + 1
		End if
	Next

	'Determine if there are multiple pages and if so, display page numbers.
	If intTotPages > 1 Then
		Response.Write "<td colspan='" & intPicsPerRow & "' align='center'><font face='Verdana,Arial' size='1'><b>"
		For x = 1 to intTotPages
			If x = intPage Then
				Response.Write "</font><font face='Verdana,Arial' size='1' color=red>pag. " & x & "</font><font face='Verdana,Arial' size='1'>&nbsp;&nbsp;&nbsp;&nbsp;"
			Else
				Response.Write "<a href='DocumentsAlbum.asp?Page=" & x & "&ShowSub=" & ShowSub & "'></font><font face='Verdana,Arial' size='1'> " & x & "</font></a>&nbsp;&nbsp;&nbsp;&nbsp;"
			End If
		Next
		Response.Write "</b></font></td>"
		Response.Write "</tr><tr><td>&nbsp;</td></tr><tr>"
	End If


	For x = 0 to UBound(strPicArray,2)-1
	If CInt(strPicArray(1,x)) = intPage Then
     ShowPic = Replace(strPicArray(0,x), " ", "%20")
   	  Response.write "<td align='center' width='25%'>"
	  Response.write "<br>"
	  Response.Write("<a href=""../public/upload/"& strPicArray(0,x)&""" target=""_blank"" ><img src='../images/news_dettaglio.gif'  border=0></a>")
	  Response.Write("<br><a href=""Javascript:getImage('" & sDirUrl & strPicArray(0,x) & "')""<font color=""" & strBaseFontColor & """><b>" & strPicArray(0,x) & "</b></font><br><br>")
	  Response.write "</a></td>" & vbcrlf

	  PictureNo = PictureNo + 1
	  If PictureNo=intPicsPerRow Then
		  Response.write "</tr><tr>"
		  PictureNo = 0
	  End if
	End If
	Next



    Set objFSO = Nothing
  End if
  %>
    </tr>
  </table>
  <%
End if
%>
</div>
</html>






