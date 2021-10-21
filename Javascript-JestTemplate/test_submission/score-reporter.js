class ScoreReporter {

    constructor(globalConfig, options) {
      this._globalConfig = globalConfig;
      this._options = options;
      this.json_results = {"scores": { "testPassed": 0}};
    }
  
    onTestResult(test, testResult){
      
      let result = this.json_results;

      console.log('Custom reporter output:');
      console.log('testResult',testResult.testResults);
      
      testResult.testResults.forEach(function (item) {
        if(item.status == 'passed'){
          result["scores"]["testPassed"] += 1;
        }
      });
    }

    onRunComplete(){
      console.log(this.json_results);
    }
}

module.exports = ScoreReporter;