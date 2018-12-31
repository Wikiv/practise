# python check_cmx.py -w 10 -c 5 -u http://localhost:30000/getMonitorStatus -i DB
import requests
import json
import sys, getopt
import time

w_per = 0
c_per = 0
url=""
info=""
cmx_OK = "CMX OK "
cmx_fail = "CMX FAIL "
f_cnt = "f_cnt"
s_cnt = "s_cnt"
exit_status=3

class CheckCMX:
	def __init__(self):
		self.succ_fail_str=""
		self.fcnt = 0
		self.scnt = 0
		self.totcnt = 0
		self.c_time = ""
		self.chart_str=""

	def getSuccessFailure(self,jObj):
		global exit_status
		try:
			s_per = 0
			if f_cnt in jObj and s_cnt in jObj:
				self.fcnt = jObj[f_cnt]
				self.scnt = jObj[s_cnt]
                		self.totcnt = self.fcnt + self.scnt 
	
				if int(self.fcnt) >= int(c_per):
					exit_status = 2
				elif int(self.fcnt) >= int(w_per):
					exit_status = 1
				else:
					exit_status = 0
				
				if self.totcnt == 0:
					self.succ_fail_str = "- None"
				else:
					self.succ_fail_str = "- " + str(self.fcnt) + " failed"
 
				return True
			else:
				self.succ_fail_str = " Unable to get success/failure count in response."
				exit_status = 3
				return False
		except ValueError, e:
			self.succ_fail_str = " Error in parsing response."
			exit_status = 3
			return False
		
	def get_chart_data(self):
		self.chart_str = "'failure'="+str( self.fcnt)+";;;;;"			
		return True

	def is_json(self,jObj):
		try:	
			j = json.loads(jObj);
		except ValueError, e:
			return False
		return True

	def json_parse(self,resp):
		global exit_status
		self.c_time = time.strftime('%Y/%m/%d %H:%M:%S %p');
		result = ""
		status = ""
		if self.is_json(resp):
			jObj = json.loads(resp)
			if self.getSuccessFailure( jObj ):
				result += cmx_OK
				result += self.succ_fail_str + " - " + self.c_time
				self.get_chart_data();
				result += " |" + self.chart_str
			else:
				result = cmx_fail + self.succ_fail_str 
				
		else:
			result += cmx_fail + "Invalid response received." # Invalid json found.
			exit_status = 3
	
		print result


try:
	opts, args = getopt.getopt(sys.argv[1:],"hw:c:u:i:",["warn=","crit=","url=","info="])
except getopt.GetoptError,e:
	print "Exception catched in commandLine parse,",e
	sys.exit(3)

for opt, arg in opts:
	if opt == '-h':
		print 'check_cmx.py -w <warning count> -c <critical count> -u <service url> -i <info>'
		sys.exit()
	elif opt in ("-w","--warn"):
		w_per = arg
	elif opt in ("-c","--crit"):
		c_per = arg
	elif opt in ("-u","--url"):
		url = arg
	elif opt in ("-i","--info"):
		info = arg


payload = json.loads('{}')
payload["info"] = info
try:
	r = requests.post(url, data=json.dumps(payload))

	if r.status_code == 200:
		c_cmx = CheckCMX()
		c_cmx.json_parse(r.text)
	else:
		print "Error in API response."

except Exception,e:
	print "Exception catched during in service call.",e
	exit_status = 3

sys.exit(exit_status)
 
