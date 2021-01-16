
Testps.dll: dlldata.obj Test_p.obj Test_i.obj
	link /dll /out:Testps.dll /def:Testps.def /entry:DllMain dlldata.obj Test_p.obj Test_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Testps.dll
	@del Testps.lib
	@del Testps.exp
	@del dlldata.obj
	@del Test_p.obj
	@del Test_i.obj
