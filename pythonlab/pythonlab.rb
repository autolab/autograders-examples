require "AssessmentBase.rb"

module Pythonlab
  include AssessmentBase

  def assessmentInitialize(course)
    super("pythonlab",course)
    @problems = []
  end

end
