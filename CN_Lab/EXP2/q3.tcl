set ns [new Simulator]

set namfile [open ex_02.nam w]
$ns namtrace-all $namfile

set tracefile [open ex_02.tr w]
$ns trace-all $tracefile    

Agent/TCP set packetSize_ 1500

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 1Mb 10ms DropTail

set tcp [new Agent/TCP]
$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink  

$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

set filesize [expr 10*1024*1024]
$ns at 0.0 "$ftp send $filesize"

proc finish {} {            
global ns namfile tracefile        
$ns flush-trace      
close $namfile      
close $tracefile        
set awkCode {  
BEGIN {}  {
if ($1 == "r" && $4 == 1 && $6 > 1500) {
count = count + $6 - ($6 % 1500);
print $2, count >> "ex_02.data";
}  } END{}
}        
exec awk $awkCode ex_02.tr        
exec nam ex_02.nam &        
exec xgraph -bb -tk -x Time -y Bytes ex_02.data -bg white &        
exit 0
}

$ns at 100.0 "finish"
$ns run
