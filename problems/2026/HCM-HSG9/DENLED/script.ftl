<#-- Subtask 1 -->
<#list 1..1 as i>
gen ${i} --min_n=1 --max_n=1 --max_val=50 --subtask=1 > $
</#list>
<#list 1..9 as i>
gen ${i} --min_n=1 --max_n=20 --max_val=50 --subtask=1 > $
</#list>

<#-- Subtask 2 -->
<#list 1..10 as i>
gen ${i} --min_n=1000 --max_n=1000 --min_k=2 --max_k=2 --max_val=1000000000 --subtask=2 > $
</#list>

<#-- Subtask 3 -->
<#list 1..10 as i>
gen ${i} --min_n=1000 --max_n=1000 --max_val=1000000000 --bound=10000 --subtask=3 > $
</#list>

<#-- Subtask 4 -->
<#list 1..10 as i>
gen ${i} --min_n=1000 --max_n=1000 --max_val=1000000000 --subtask=4 > $
</#list>
