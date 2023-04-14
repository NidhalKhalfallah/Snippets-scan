import { ApplicationLoadBalancer, ApplicationLoadBalancerProps, Certificate, Listener } from '@aws-cdk/aws-elasticloadbalancingv2';
import { AutoScalingGroup } from '@aws-cdk/aws-autoscaling';
declare const asg: AutoScalingGroup;
declare const vpc: ec2.Vpc;
const alb = new ApplicationLoadBalancer(this, 'ALB', {
	vpc: vpc,
	internetFacing: true
  });
  //Create a listener for alb
  const listener = new Listener(this, 'Listener', {
    port: 80,
    protocol: 'HTTP',
    targetGroupArn: alb.targetGroupArn,
    loadBalancerArn: alb.loadBalancerArn,
    healthCheckPath: '/',
    healthCheckIntervalSeconds: 5,
    healthCheckTimeoutSeconds: 5,
    healthyThresholdCount: 2,
    unhealthyThresholdCount: 2,
    healthyThresholdPercentage: 80,
    unhealthyThresholdPercentage: 80,
    healthCheckType: 'HTTP',
    healthyThresholdCount: 2,
    unhealthyThresholdCount: 2,
    healthyThresholdPercentage: 80,
    unhealthyThresholdPercentage: 80