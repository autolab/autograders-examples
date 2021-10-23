class ScoreReporter {

    constructor(globalConfig, options) {
      this._globalConfig = globalConfig;
      this._options = options;
      
      // this is the score that we will be modifiying
      this.json_results = {"scores": { "testPassed": 0}};
    }
  
    // update the scores when test is done
    onTestResult(test, testResult){
      
      let result = this.json_results;
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