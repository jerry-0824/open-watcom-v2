#pmake: build serv remote os_nt cpu_i86 cpu_386 tcp x86
host_cpu = 386
host_os  = nt

target_cpu = x86
target_os  = nt

srv = tcp
which = SERVER
gui = 1
remote_link = 1

extra_cppflags = -DGUISERVER

extra_linker = lib wsock32.lib

!include $(trap_dir)/master.mif
