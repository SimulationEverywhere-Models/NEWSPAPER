[top]
components : jour

in   : in
out  : out
Link : in in@jour
Link : out@jour out

[jour]
components : p_j@p_journalist
components : t_j@t_journalist

in   : in
out  : out
Link : in in@p_j
link : out@p_j out
Link : in in@t_j
Link : out@t_j out

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

