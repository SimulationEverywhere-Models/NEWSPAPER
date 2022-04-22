[top]
components : jour
components : office
components : pr@printer

in   : in
out  : out
Link : in in@jour
Link : out@jour in@office
Link : out@office in@pr
Link : out@pr out

[jour]
components : p_j@p_journalist
components : t_j@t_journalist

in   : in
out  : out
Link : in in@p_j
link : out@p_j out
Link : in in@t_j
Link : out@t_j out

[office]
components : ed@editor
components : mk@makeup
components : ch@chiefEditor

in   : in 
out  : out

Link : in in@ed
Link : out@ed in@mk
Link : out@mk in@ch
Link : out@ch done@ed
Link : out@ch out

[p_j]

preparation : 00:00:05:000  
distribution : normal
mean : 7
deviation : 1

[t_j] 

preparation : 00:00:05:000  
distribution : normal
mean : 7
deviation : 1

[ed] 

preparation : 00:00:05:000  
distribution : normal
mean : 7
deviation : 1

[mk] 
preparation : 00:00:05:000  
distribution : normal
mean : 7
deviation : 1

[ch] 
preparation : 00:00:05:000  
distribution : normal
mean : 7
deviation : 1

[pr]
preparation : 00:00:05:000  
distribution : normal
mean : 7
deviation : 1

