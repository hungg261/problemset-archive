<#assign E5 = 100000>
<#assign E9 = 1000000000>

<#-- Subtask 1 -->
<#list 1..1 as i>
gen ${i} --max_n=0 --min_t=${E9 / 2} --max_t=${E9} --min_q=5 --max_q=20 --param=edge > $
</#list>

<#list 1..7 as i>
gen ${i} --max_n=0 --min_t=${E9} --max_t=${E9} --min_q=${E5} --max_q=${E5} --param=edge > $
</#list>

<#-- Subtask 2 -->
<#list 1..8 as i>
gen ${i} --min_n=1 --max_n=1 --min_t=${E9} --max_t=${E9} --min_q=${E5} --max_q=${E5} --param=edge --exclude="-" > $
</#list>

<#-- Subtask 3 -->
<#list 1..3 as i>
gen ${i} --max_n=999 --min_t=1000 --max_t=1000 --max_q=1000 --param=edge > $
</#list>

<#list 1..5 as i>
gen ${i} --max_n=999 --min_t=1000 --max_t=1000 --min_q=1000 --max_q=1000 --param=edge > $
</#list>

<#-- Subtask 4 -->
<#list 1..3 as i>
gen ${i} --max_n=${E5 - 10} --min_t=${E5} --max_t=${E5} --max_q=${E5} --param=edge > $
</#list>

<#list 1..5 as i>
gen ${i} --min_n=${E5 - 10} --max_n=${E5 - 1} --min_t=${E5} --max_t=${E5} --min_q=${E5} --max_q=${E5} --param=edge > $
</#list>

<#-- Subtask 5 -->
<#list 1..3 as i>
gen ${i} --max_n=${E5} --max_t=${E9} --max_q=${E5} --param=edge > $
</#list>

<#list 1..5 as i>
gen ${i} --min_n=${E5} --max_n=${E5} --min_t=${E9} --max_t=${E9} --min_q=${E5} --max_q=${E5} --param=edge > $
</#list>
