require "AssessmentBase.rb"

module Factlab
  include AssessmentBase

  def assessmentInitialize(course)
    super("factlab", course)
    @problems = []
  end

end
