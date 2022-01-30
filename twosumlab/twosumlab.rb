require "AssessmentBase.rb"

module Twosumlab
  include AssessmentBase

  def assessmentInitialize(course)
    super("twosumlab",course)
    @problems = []
  end

end
